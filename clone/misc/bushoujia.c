// bushou jia.c ���޼�
// Create by Vin for Heros.cn

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(NOR + CYN "���޼�" NOR, ({ "bushou jia", "bushou", "jia" }));
        set_weight(3000);
        set("long", NOR + CYN "�гݷ����Ĳ��޼У����ͨ��������("
                    HIY "snare" NOR + CYN ")���������ԡ�\n" NOR);
        set("unit", "ֻ");
        set("value", 10000);
        set("no_sell", 1);
        setup();
}

void init()
{
        add_action("do_snare", "snare");
}

int do_snare(string arg)
{
        object ob;
        object me;
        int time;

        me = this_player();

        if (me->query_skill("hunting", 1) < 20)
                return notify_fail("������Լ��ɲ�����죬���Բ������塣\n");

        if (query_temp("id") != me->query("id")
           && query_temp("id")
           && environment() != me)
                return notify_fail("���Ǳ��˷��õĲ��޼У��㶯��������\n");

        if (environment(me)->query("no_fight")
           || environment(me)->query("no_quarry"))
                return notify_fail("��������ò��޼У���̫�ðɡ�\n");

        if (query_temp("snare"))
                return notify_fail("���޼��Ѱ������ƣ��͵������Ϲ��ˡ�\n");

        if (me->is_busy())
                return notify_fail("��������æ���أ���һ����ɡ�\n");

        if (me->is_fighting())
                return notify_fail("�����Ȱ�����ǰ�ļһ�ŵ���˵�ɡ�\n");

        if (! objectp(ob = present("shi er", me))
           || ! ob->query_amount())
                return notify_fail("����������û��ʳ�������Բ������塣\n");

        ob->add_amount(-1);

        message_vision(HIR "\n$N" HIR "��" + name() + HIR "�����ʳ��������"
                       "�����ڵ��ϣ��ȴ������Ϲ���\n\n" NOR, me);

        set_temp("snare", 1);
        set_temp("id", me->query("id"));

        if (environment() == me)
        {
                this_object()->move(environment(me));
                set("no_get", "���޼еĵ�����Ȼ�������Ҷ�С�����ˡ�\n");
        }

        me->move(environment(me));

        time = 12 + random(12);

        remove_call_out("catch_quarry");
        call_out("catch_quarry", time, me);
        me->start_busy(time / 2 + 1);
        return 1;
}

void back_owner(object me)
{
        if (environment() != me)
        {
                this_object()->move(me);

                if (! me->is_busy())
                        me->start_busy(1);
        }
}

void catch_quarry(object me)
{
        object env;
        object quarry;
        mapping rs;
        string *st, msg;
        int i;
        int sum;
        int lvm, lvq, dam;

        delete_temp("snare");
        delete_temp("id");
        delete("no_get");

        env = environment(this_object());
        if (! objectp(me) || environment(me) != env || ! living(me))
        {
                message_vision(CYN "ֻ�������꡹һ�������޼��Զ�"
                               "��£�ˡ�\n" NOR, this_object());
                return;
        }

        if (! mapp(env->query("quarrys"))
           || env->query("no_quarry")
           || env->query("no_fight"))
        {
                message_vision(CYN "���˰��죬ֻ�������꡹һ��������"
                               "���Զ���£�ˣ�ɶҲûץ����\n" HIC "��"
                               "������ط���׽����ʲô��$N" HIC "̾��"
                               "�����������޼��ջء�\n" NOR, me);
                back_owner(me);
                return;
        }

        // ���øõ�ͼ������
        rs = env->query("quarrys");

        st = keys(rs);
        sum = 0;

        for (i = 0; i < sizeof(st); i++)
        {
                if (! intp(rs[st[i]]))
                        rs[st[i]] = 0;

                sum += rs[st[i]];
        }

        if (! sum)
                return;

        sum = random(sum);

        for (i = 0; i < sizeof(st); i++)
        {
                if (sum < rs[st[i]])
                {
                        catch(quarry = new("/clone/quarry/" + st[i]));

                        if (! objectp(quarry))
                        	catch(quarry = new("/clone/beast/" + st[i]));

                        if (! objectp(quarry))
                                break;

                        msg = HIY "\n�������ã�$N" HIY "����Ȼ�γ�һ" +
                              quarry->query("unit") + HIY + quarry->name() +
                              HIY "���ŵö���󳯲��޼�����������" NOR;

                        // �趨�����ߣ������ԵĽ�������
                        quarry->set("owner", me->query("id"));
                        quarry->move(environment(me));

                        lvm = me->query_skill("hunting", 1) / 2;
                        lvq = quarry->query("power");
                        dam = lvm + random(lvm * 2);

                        if (lvm / 2 + random(lvm) < lvq && lvq <= 20)
                        {
                                msg += HIY "���ڴ�ʱ�����������꡹һ������"
                                       "���޼о�Ȼ�Զ������ˡ�$n" HIY "�ܾ�"
                                       "֮�¼�æ���ӣ���ʧ�����������\n"
                                       "\n" NOR;
                                message_sort(msg, me, quarry);
                                destruct(quarry);
                        } else
                        if (lvm / 2 + random(lvm) < lvq && lvq > 20)
                        {
                                msg += HIY "�������ʱ�򣬺�Ȼ���á����꡹"
                                       "һ������ֻ���޼о�Ȼ�Զ������ˡ�$n"
                                       HIY "�ܾ�֮�²�Ȼ��ŭ����$N" HIY "ֱ"
                                       "�˶�ȥ��\n\n" NOR;
                                message_sort(msg, me, quarry);
                                quarry->kill_ob(me);
                        }  else
                        if (lvm / 2 + random(lvm) > lvq * 4)
                        {
                                msg += HIY "ֻ����ž����һ����$n" HIY "ֻ��"
                                       "��ʳ��������������˲��޼��ϵ����塣"
                                       "�����������Ϊ�����$n" HIY "��ס"
                                       "��������Ѫ�����Ĵ����ǡ���ֻ����Ƭ��"
                                       "������û�˶�����\n" NOR;
                                message_sort(msg, me, quarry);
                                quarry->die(me);
                        }  else
                        if (lvm / 2 + random(lvm) > lvq * 3)
                        {
                                msg += HIY "ֻ����ž����һ����$n" HIY "ֻ��"
                                       "��ʳ��������������˲��޼��ϵ����壬"
                                       "��ʱ���е���Ѫֱ������$n" HIY "��ͣ"
                                       "������ͼ���ܣ���������˿ڣ���ʱʹ��"
                                       "���˹�ȥ��\n" NOR;
                                message_sort(msg, me, quarry);
                                quarry->unconcious(me);
                        } else
                        {
                                msg += HIY "ֻ����ž����һ����$n" HIY "ֻ��"
                                       "��ʳ��������������˲��޼��ϵ����壬"
                                       "��ʱ���е���Ѫֱ����ʹ��������\n\n" NOR;
                                message_sort(msg, me, quarry);
                                quarry->receive_wound("qi", dam, me);
                                quarry->receive_wound("jing", dam, me);
                                quarry->kill_ob(me);
                        }
                        me->start_busy(1);
                        return;
                }
                sum -= rs[st[i]];
        }
        message_vision(CYN "���˰��죬ֻ�������꡹һ�������޼��Զ�"
                       "��£�ˣ�ɶҲûץ����\n" HIC "$N" HIC "����"
                       "���죬ҡ��ҡͷ�������޼��ջء�\n" NOR, me);
        back_owner(me);
}
