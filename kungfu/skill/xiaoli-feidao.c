inherit SKILL;

int valid_learn(object me)
{
        object ob;

        if ((int)me->query("max_neili") < 1500)
                return notify_fail("�������������û�а취��С��ɵ���\n");

        if ((int)me->query_skill("force") < 200)
                return notify_fail("����ڹ���򲻹���û�а취��С��ɵ���\n");

	if ((int)me->query_skill("throwing", 1) < (int)me->query_skill("xiaoli-feidao", 1))
		return notify_fail("��Ļ�������ˮƽ���ޣ��޷����������С��ɵ���\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage == "throwing";
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 40)
                return notify_fail("�����������û�а취��ϰС��ɵ���\n");

        if ((int)me->query("neili") < 50)
                return notify_fail("�������������û�а취��ϰС��ɵ���\n");

        me->receive_damage("qi", 35);
        me->add("neili", -48);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"xiaoli-feidao/" + action;
}
