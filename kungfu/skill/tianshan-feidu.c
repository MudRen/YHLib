inherit SKILL;

string *dodge_msg = ({
        "$nһʽ�������ơ�������һת���͵�����һ��,�����$N�Ĺ��ơ�\n",
        "$nһʽ�������ơ���˫��������󣬲������������״�$N��ǰ�����\n",
        "$nһʽ����Ծ�ơ������˷�����һ�����Ƶ���$N�����\n",
        "$nһʽ���ں��ơ������������һ�ˣ������ù���$N���������ơ�\n",
        "$nһʽ�������ơ�������һ�����һ�Σ�������Ʈ����Զ��\n",
        "$nһʽ�������ơ���ȫ��Ϊһ����Ӱ������һ���շ��������Ʈ���ұߡ�\n",
        "$nһʽ�������ơ�������һ����ʸ������ٿ�İεض�����$N�������ӡ�\n",
});

int valid_enable(string usage)
{
	return usage == "dodge" || usage == "move";
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if((int)me->query("qi") < 50 )
                return notify_fail("�������̫���ˣ���������ɽ�ɶɡ�\n");

        me->receive_damage("qi", 40);
        return 1;
}
