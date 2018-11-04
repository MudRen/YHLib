// wushe-qu.c ������

#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage == "guzheng-jifa"; }

int valid_learn(object me)
{
        if (me->query_skill("guzheng-jifa", 1) < 100)
                return notify_fail("��Ĺ��ݼ���ˮƽ������������������˵�ɣ�\n");

        if (me->query_skill("guzheng-jifa", 1) < me->query_skill("wushe-qu", 1))
                return notify_fail("��Ĺ��ݼ���ˮƽ���ޣ��޷������������������\n");

        return 1;
}

int practice_skill(object me)
{
        object ob;

        if (! objectp(ob = me->query_temp("handing")) ||
            ! ob->valid_as_zheng())
                return notify_fail("���ó�����������ô��ϰ��\n");

        if ((int)me->query("jing") < 80)
                return notify_fail("��ľ��񲻹��ã�û����ϰ�ˡ�\n");

        if ((int)me->query("qi") < 30)
                return notify_fail("������ʵ����̫ƣ���ˡ�\n");

        me->receive_damage("jing", 25);
        me->receive_damage("qi", 15);

        return 1;
}

void do_effect(object me)
{
        object env;
        int lvl;
        mapping rs;
        string *st;
        object snake;
        int i;
        int sum;

        lvl = me->query_skill("guzheng-jifa", 1) / 2 +
              me->query_skill("wushe-qu", 1);

        if ((env = environment(me))->query("no_fight"))
                return;

        if (lvl < 50)
        {
                write(HIC "����ͷ�󺹵ĵ��˰��죬����û��ʲô���á�\n" NOR);
                return;
        }

        if (me->query("neili") < 50)
        {
                me->set("neili", 0);
                write(HIC "����������������Щ���á�\n" NOR);
                return;
        }

        me->add("neili", -20 - random(10));

        if (! mapp(env->query("quarrys")))
        {
                write(HIY "�㵯�˰��죬����û��һ���߳�����\n" NOR);
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
        {
                write(HIY "�㵯�˰��죬�����ƺ�û��ʲô�߳�����\n" NOR);
                return;
        }

        sum = random(sum);

        for (i = 0; i < sizeof(st); i++)
        {
                if (sum < rs[st[i]])
                {
                        catch(snake = new("/clone/beast/" + st[i]));

                        if (! objectp(snake) || ! snake->is_snake())
                        {
                                write(HIY "�㵯�˰��죬�����ƺ�û��ʲô�߳�����\n" NOR);
                                return;
                        }

                        snake->add("snake_poison/level" + random(lvl / 5));
                        snake->move(env);
                        write(HIR "�㵯��һ����ֻ��һ���������죬һ��" +
                              snake->name() + HIR "�Ӳݴ��д��˳�����\n" NOR);
                        return;
                }
                sum -= rs[st[i]];
        }
}
