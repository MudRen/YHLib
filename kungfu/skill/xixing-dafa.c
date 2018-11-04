#include <ansi.h>

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_force(string force)
{
        return 1;
}

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("xixing-dafa", 1);
        return lvl * lvl * 15 * 20 / 100 / 200;
}

int valid_learn(object me)
{
        int lvl = (int)me->query_skill("xixing-dafa", 1);

        if (me->query("character") == "��������")
                return notify_fail("�����а��������ֺ��˵��书����ѧ��������\n");

        if (me->query("con") < 30)
                return notify_fail("�����Ű��շ�����ת��һ����Ϣ����Ȼ�����Ļ���"
                                   "�٣�����ȴ��һ�������\n");

        if ((int)me->query_skill("force", 1) < 100)
                return notify_fail("��Ļ����ڹ���Ϊ���㣬�����������Ǵ󷨡�\n");

        if (! me->query("can_learn/xixing-dafa/ren")
           && me->query("max_neili")
           && lvl < 200
           && lvl >= 10)
                return notify_fail("��û�а������Ǵ󷨵ľ��Ͻ�����ɢȥ�����ڻ���"
                                   "�����Լ������д󷨡�\n");

        return ::valid_learn(me);
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mapping result;
        int ap, dp;
        int jiali;

        if ((int)me->query_skill("xixing-dafa", 1) < 80
           || ! living(me))
                return;

        if ((jiali = ob->query("jiali")) < 1
            || ob->query_skill_mapped("force") == "taixuan-gong")
                return;

        ap = ob->query_skill("force");
        dp = me->query_skill("force");
        if (ap / 2 + random(ap) < dp)
        {
                if (me->query("neili") < me->query("max_neili") * 15 / 10)
                        me->add("neili", jiali);

                result = ([ "damage" : -damage ]);

                switch (random(4))
                {
                case 0:
                        result += ([ "msg" : HIM "$N" HIM "ֻ��������ԴԴ��к"
                                             "�����ɵô��һ����\n" NOR ]);
                        break;
                case 1:
                        result += ([ "msg" : HIM "$N" HIM "ֻ���÷�����������"
                                             "��ʯ���󺣣���֪���١�\n" NOR ]);
                        break;
                case 2:
                        result += ([ "msg" : HIM "$N" HIM "ֻ���÷�����������"
                                             "��Ӱ���٣���Ȼ��֪���䡣\n" NOR ]);
                        break;
                default:
                        result += ([ "msg" : HIM "$N" HIM "��ס�߶�����������"
                                             "ֻ����$n���ƺ���������\n" NOR ]);
                        break;
                }
                return result;
        }
}

int practice_skill(object me)
{
        return notify_fail("���Ǵ�ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

void check_count(object me)
{
        if (! me->query("can_learn/xixing-dafa/ren")
           && me->query("max_neili") >= 3000
           && me->query("exception/xixing-count") > 1000)
        {
                me->apply_condition("xixing-fanshi",
                        me->query_condition("xixing-fanshi") +
                        me->query("exception/xixing-count") / 10);
                me->delete("exception/xixing-count");
        }
}

void skill_improved(object me)
{
        me->add("exception/xixing-count", me->query_skill("xixing-dafa", 1) + 1);
        check_count(me);
}

string exert_function_file(string func)
{
        return __DIR__"xixing-dafa/" + func;
}
