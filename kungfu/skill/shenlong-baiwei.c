#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N���ƻ��أ�����ʹһ�С�������β���ζ��Ż���$n��$l",     
        "dodge"  : 45,
        "parry"  : 45,
        "force"  : 220,
        "damage" : 70,
        "damage_type": "����"
]),
});

string main_skill()
{
        return "xianglong-zhang";
}

int valid_enable(string usage)
{
        return usage == "strike";
}

int valid_learn(object me)
{
        if (me->query_skill("xianglong-zhang", 1) > 0)
                return notify_fail("���Ѿ�ѧȫʮ�����ˣ������ٵ���ѧϰ��\n");

        if (me->query("character") == "���ռ�թ")
                return notify_fail("�����а��룺���书�����ý���ѧ��������\n");

        if ((int)me->query("str") < 36)
                return notify_fail("�����������������������������ʮ���ơ�\n");

        if ((int)me->query("con") < 32)
                return notify_fail("����������������������������ʮ���ơ�\n");

        if ((int)me->query_skill("force") < 300)
                return notify_fail("����ڹ���򲻹���������������ʮ���ơ�\n");

        if ((int)me->query("max_neili") < 3000)
                return notify_fail("���������Ϊ���㣬������������ʮ���ơ�\n");

        if ((int)me->query_skill("strike", 1) < 180)
                return notify_fail("��Ļ����Ʒ���򲻹���������������ʮ���ơ�\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("shenlong-baiwei", 1))
                return notify_fail("��Ļ����Ʒ�ˮƽ���ޣ��޷���������Ľ���ʮ���ơ�\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        // ��Ϊ�漰������ʹ�̶�NPC����ʩչʱ������ǿ
        if (! userp(me))
                return ([ "action" : WHT "$N" WHT "���ƻ��أ�������Ȼʹһ�С�"
                                     HIY "������β" NOR + WHT "�����»ζ��Ż�"
                                     "��$n" WHT "��$l" WHT,
                          "attack" : 300,
                          "dodge"  : 300,
                          "parry"  : 300,
                          "damage" : 300,
                          "force"  : 500,
                          "damage_type": "����" ]);

        return action[random(sizeof(action))];
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        // Ϊ������趨��ԭ��ͬ��
        if (userp(me) || damage_bonus < 150)
                return 0;

        victim->receive_wound("qi", (damage_bonus - 80) / 2, me);

        return random(2) ? HIR "ֻ��$n" HIR "ǰ�ء����꡹һ�����죬������"
                           "�߹Ƕ��۵�������\n" NOR:

                           HIR "$n" HIR "һ���ҽУ���ǰ���������꡹������"
                           "�죬������Ѫ���硣\n" NOR;
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 120)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 50)
                return notify_fail("�����������������ʮ���ơ�\n");

        me->receive_damage("qi", 100);
        me->add("neili", -40);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"shenlong-baiwei/" + action;
}
