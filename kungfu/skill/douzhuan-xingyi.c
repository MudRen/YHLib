// douzhuan-xingyi ��ת����

#include <ansi.h>
#include <combat.h>

inherit SKILL;

string *parry_msg = ({
        "ֻ�������ϡ�һ����$n�ñ�������һ�У�������$N��һ����\n",
        "���Ǳ�$n�����б���ж����\n",
        "����$n����һ�࣬����ת�����еı��У���$N�о���������ʩ��\n",
});

string *unarmed_parry_msg = ({
        "���Ǳ�$p˫��һ�ƣ�$N�Ĺ��ƶ�ʱ���˷���\n",
        "$n����һת��$Nֻ���õ����е�����ȫ�����䵽�˿մ���\n",
        "����$N�о�����޻���һ����˵�����Ĺ��졣\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int valid_enable(string usage) { return usage == "parry"; }

int valid_learn(object me)
{
          if ((int)me->query_skill("murong-xinfa", 1) < 100)
                  return notify_fail("���Ľ���ķ���򻹲���������ѧϰ��ת���ơ�\n");

        if ((int)me->query_skill("parry", 1) < 100)
                return notify_fail("��Ļ����мܼ������յĻ������������޷�ѧϰ��ת���ơ�\n");

        return 1;
}

int practice_skill(object me)
{
	return notify_fail("��ת����ֻ����ѧ(learn)�������������ȡ�\n");
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mixed result;
        int ap, dp, mp;
        int lvl, ran;
        string msg;

        if ((int) me->query_skill("douzhuan-xingyi", 1) < 100 ||
              ! living(me) || me->query_skill("zihui-xinfa",1) < 100)
                return;

        mp = ob->query_skill("count", 1);
        ap = ob->query_skill("force", 1) + mp;
        dp = me->query_skill("parry", 1);
 
        lvl = me->query_skill("douzhuan-xingyi", 1);
      
        // ���ⷴ�˺�����
        if (lvl > 280)ran = 50;
        if (lvl > 300)ran = 45;
        if (lvl > 320)ran = 35;
        if (lvl > 350)ran = 30;
        if (lvl > 380)ran = 20;
        if (lvl > 400)ran = 10;
        if (lvl > 450)ran = 8;
        if (lvl > 500)ran = 6;

        // ��ת���Ʒ���Ч��
        if (lvl > 280 &&
            me->query_skill("zihui-xinfa", 1) > 300 &&
            ! me->is_busy() &&
            me->query("max_neili") * 2 / 3 > ob->query("max_neili") &&
            me->query("neili") > 500 &&
            mp < 100 &&
            random(ran) == 1 )
        {
                msg = HIM "\n$N" HIM "Ĭ���ϻ��ķ���ʩչ���ѧ����ת���ơ���һ������������Ѹ�ٹ��У�"
                      "�����ǣ����$n" HIM "����ʽ��\n" NOR;

                ap = me->query_skill("parry");
                dp = ob->query_skill("force");

                me->add("neili", -150);

                if (dp / 2 + random(dp) < ap)
                {
                      damage = ap + dp;
                      msg += COMBAT_D->do_damage(me, ob, REMOTE_ATTACK, damage, 200,
                                                 HIR "\n$n" HIR "���һ��������$N" HIR "����"
                                                 "$p" HIR"��ǰ����ʽ�����ۻط������Լ���\n��"
                                                 "Ȼ��$n" HIR "һ���Һ�����Ȼ���ܲ�����\n" NOR);
                } else {

                      msg += HIC "$n" HIC "�ۼ�$P������ӿ������"
                             "���⣬ʩ������������⿪����\n" NOR;
                }
                
                message_sort(msg, me, ob);

                result = ([ "damage" : -damage ]);
                result += ([ "msg" : msg ]);

                return result;
                
        } else
           
        if (ap / 2 + random(ap) < dp)
        {
                result = ([ "damage" : -damage ]);

                switch (random(3))
                {
                case 0:
                        result += ([ "msg" : HIC "$n" HIC "���κ�Ȼת����ͣ��$N"
                                             HIC "��һ�о�Ȼ�޴����֡�\n" NOR ]);
                        break;
                case 1:
                        result += ([ "msg" : HIC "$n" HIC "����һ�У�$N"
                                             HIC "��ʱ����׼����������"
                                            "����һ�����������ĸо���\n" NOR ]);
                        break;

                default:
                        result += ([ "msg" : HIC "$N" HIC "һ���ۿ�������$n"
                                             HIC "��Ȼ��$n" HIC "����һж��"
                                             "��$N" HIC "�Ĺ������������Ρ�\n" NOR ]);
                        break;
                }
                return result;
        } else

        if (mp >= 100)
        {
                switch (random(3))
                {
                case 0:
                        result = HIY "$n" HIY "���κ�Ȼת����ͣ��Ȼ��$N"
                                 HIY "���ѿ������а��˿������Ӱ�죬����ֱ�롣\n" NOR;
                        break;

                case 1:
                        result = HIY "$n" HIY "����һ�У�$N"
                                 HIY "��������׼��������Ȼ���ѣ���ʱ�仯��ʽ��\n" NOR;
                        break;

                default:
                        result = HIY "$n" HIY "����һж��������$N"
                                 HIY "��Ȼ��������������ǧ��ı仯��������Ų����$n"
                                 HIY "�������̾ʹ���ա�\n" NOR;
                        break;
                }
                COMBAT_D->set_bhinfo(result);
        }
}

string perform_action_file(string action)
{
        return __DIR__"douzhuan-xingyi/" + action;
}
