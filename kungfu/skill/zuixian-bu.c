inherit SKILL;

string *dodge_msg = ({
    "$nһʽ������Ǭ���������ӳ���һת��$Nֻ������ǰһ����ʧȥ��Ŀ�ꡣ\n",
    "$nһʽ��̫����ơ���˫�ŵ�أ�����ͻȻ�θ�����������Ʈ����$N���\n",
    "$nһʽ�����л�Ӱ��������һ�Σ���ʱ��������Ӱһ���ӳ�����$N����ǰ��\n",
    "$nһʽ���������¡���ƮȻ���һ�ˣ��㿪$N���������ơ�\n",
    "$nһʽ�������ƻá������弱ת����Ϊһ���׹⣬��ò����ĳ�����$N����Χ��\n",
});

int valid_enable(string usage)
{
        return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
        return 1;
}

string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
    if( (int)me->query("qi") < 100 )
        return notify_fail("�������̫���ˣ��������������²���\n");

    me->receive_damage("qi", 80);
    return 1;
}

