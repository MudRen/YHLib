// qingfu-shenfa.c ������
// pal 1997.05.26
// modify by rcwiz 2003

#include <ansi.h>

inherit SKILL;

string *dodge_msg = ({
	"ֻ��$nһ�С�����Ǭ���������ζ�Ȼ���𣬶����$N��һ�С�\n",
	"$nһʽ���������١������λζ�����һ��Ʈ�����ܿ���$N��һ�С���\n"
	"$nʹ�������츣�ء���һ�����Ľ��󷭳����ܿ���$N���������ơ�\n",
	"$nһ�С��������𡹣�������ת��$Nֻ����ǰһ����$n������$N�����\n",
});

int valid_enable(string usage)
{
	return (usage == "dodge") || (usage == "move");
}

int valid_learn(object me)
{
        if (me->query("dex") < 26)
                return notify_fail("��������̫��޷�ѧϰ��������\n");

        if (me->query_skill("dodge", 1) < 100)
                return notify_fail("���Ṧ�������㣬�޷�ѧϰ��������\n");

        return 1;
}


string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int query_effect_dodge(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("qingfu-shenfa", 1);
        if (lvl < 50)  return 0;
        if (lvl < 100) return 10;
        if (lvl < 150) return 20;
        if (lvl < 200) return 30;
        if (lvl < 250) return 40;
        if (lvl < 300) return 50;
        if (lvl < 350) return 60;
        return 80;
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mixed result;
        int ap, dp, mp;

        if ((int)me->query_skill("qingfu-shenfa", 1) < 100 ||
            ! living(me) || random(3) != 1)
                return;

        mp = ob->query_skill("count", 1);
        ap = ob->query_skill("dodge") + mp;
        dp = me->query_skill("dodge", 1) / 2 +
             me->query_skill("qingfu-shenfa", 1);

        if (ap / 2 + random(ap) < dp)
        {
                result = ([ "damage": -damage ]);

                switch (random(2))
                {
                case 0:
                        result += (["msg" : HIG "ֻ��$n" HIG "��Хһ������һֻ��"
                                            "��һ����������ڰ�յ�����$N" HIG 
                                            "����ȴ���˸��ա�\n" NOR]);
                        break;

                default:
                        result += (["msg" : HIG "����$n" HIG "����ӯ�ޱȣ���ȻԾ"
                                    "�ߺ������£���$N" HIG "��ȫ�޴ӹ�����\n" NOR]);
                        break;
                }
                return result;
        } else
        if (mp >= 100)
        {
                switch (random(2))
                {
                case 0:
                        result = HIY "ֻ��$n" HIY "��Хһ������һֻ��"
                                 "��һ����������ڰ�յ���������$N"
                                 HIY "��ͨ������������ʵ������������\n" NOR;

                default:
                        result = HIY "����$n" HIY "����ӯ�ޱȣ���ȻԾ"
                                     "�ߺ������£�$N" HIY "����˼������"
                                     "����У����������޷���\n" NOR;
                        break;
                }
                COMBAT_D->set_bhinfo(result);
        }
}


int practice_skill(object me)
{
        if( (int)me->query("qi") < 60 )
                return notify_fail("�������̫���ˣ���������������\n");

        if( (int)me->query("neili") < 60 )
                return notify_fail("���������������������\n");

        me->receive_damage("qi", 50);
        me->add("neili", -55);
        return 1;
}

