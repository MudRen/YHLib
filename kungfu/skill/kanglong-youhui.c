inherit SKILL;

mapping *action = ({
([      "action" : "$N˫��ƽƽ�ᵽ��ǰ����ɫ���صĻ���ʩ���������лڡ�����$n��$l",
        "dodge"  : -20,
        "parry"  : 10,
        "force"  : 285,
        "damage" : 60,
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

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("kanglong-youhui", 1))
                return notify_fail("��Ļ����Ʒ�ˮƽ���ޣ��޷���������Ľ���ʮ���ơ�\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
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
        return __DIR__"kanglong-youhui/" + action;
}
