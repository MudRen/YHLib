inherit SKILL;

string *dodge_msg = ({
    "$n��������Ȱ�һ�Σ�ɲ�Ǽ���Զȥ����֮�⣬$N��ʱ���˸��ա�\n",
    "$n�����ж�ʱ�������һ����������$N����ʽ���Ұڶ�����ʹ��$N������ա�\n",
    "$n��һ�����̰�����$N�ɿ���ת������$Nһ��ͷ���ۻ�����æ����������\n",
    "$n�����һЦ���������ʣ�$N��������ʽ��Ȼ͸�������ԭ������һ�߻�Ӱ��\n",
});

int valid_enable(string usage)
{
    return (usage == "dodge") || (usage == "move");
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
    if( (int)me->query("qi") < 50 )
        return notify_fail("�������̫���ˣ�����������������\n");

    me->receive_damage("qi", 40);
    return 1;
}
