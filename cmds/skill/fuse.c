#include <ansi.h>
#include <command.h>

inherit F_CLEAN_UP;

int main(object me, string str)
{
        object ob, stone;
        int p, mp;

        if (! str)
                return notify_fail("��Ҫ����ʲô��Ʒ��\n");

        if (me->is_busy())
                return notify_fail("��æ����������������������ɡ�\n");

        if (me->is_fighting())
                return notify_fail("���������ڴ�ܣ�ûʱ������Щ���顣\n");

        if (! objectp(ob = present(str, me)))
                return notify_fail("������û�������Ʒ��\n");

        if (me->query_skill("force") < 300)
                return notify_fail("����ڹ���Ϊ����������������Ʒ��\n");

        if (me->query("max_neili") < 5000)
                return notify_fail("���������Ϊ����������������Ʒ��\n");

        if (me->query("neili") < 3000)
                return notify_fail("�����ڵ��������㣬����������Ʒ��\n");

        if (! ob->query("can_make") || ! ob->query("item_origin"))
                return notify_fail("�ⶫ���ƺ���������ʲô��\n");

        p = ob->query("power_point");

        message_vision(HIM "$N" HIM "��" + ob->name() +
                       HIM "�������У�ĬĬ��ת��������"
                       "ʹ���ۻ���\n" NOR, me);

        if (p < 50)
        {
                message_vision(HIR "ͻȻȴ��" + ob->name() +
                               HIR "�͵Ļ���һ�����̣�ʲô��"
                               "û�����¡�\n" NOR, me);
                destruct(ob);
                return 1;
        }

        p = random(p * 3 / 2);

        if (p > 120)
                stone = new("/clone/fam/item/stone5");
        else if (p > 90)
                stone = new("/clone/fam/item/stone4");
        else if (p > 70)
                stone = new("/clone/fam/item/stone3");
        else if (p > 50)
                stone = new("/clone/fam/item/stone2");
        else
                stone = new("/clone/fam/item/stone1");

        message_vision(HIM "��ʱֻ��$N" HIM "���İ������ڣ��ƺ���"
                       "����ʲô��ͬѰ�������顣\n" NOR, me);

        if (stone->query("value"))
        {
                mp = stone->query("value") / 300;
                mp = 5 + random(mp);
                if (mp < 5) mp = 5;
                if (mp > 100) mp = 100;

                me->add("magic_points", mp);
                tell_object(me, HIC "��ͨ������"+ stone->name() +
                                HIC "�Ĺ��̣��Ӷ������" +
                                chinese_number(mp) + "����ۡ�\n" NOR);
        }
        me->add("max_neili", -1);
        me->add("neili", -3000);
        me->start_busy(5);

        stone->set_amount(1);
        stone->move(me, 1);
        destruct(ob);
        return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ��fuse <��ƷID>

��ָ������㽫ĳЩ��Ʒ�ۻ���һ����˵�ܹ�����������ԭ�϶�����
������������������Ʒ��Ҫ�Ƚϸߵ��ڹ��ȼ���������Ϊ��ÿ�γɹ�
��������������һ����������ۣ����ǻ�����һ�����������
HELP);
        return 1;
}

