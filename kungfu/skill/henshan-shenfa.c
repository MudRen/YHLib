inherit SKILL;

string *dodge_msg = ({
        "$nһʽ������Ʈ�졹�����ӳ���һת��$Nֻ������ǰһ����ʧȥ��Ŀ�ꡣ\n",
        "$nһʽ��ֱ����������˫�ŵ�أ�����ͻȻ�θ�����������Ʈ����$N���\n",
        "$nһʽ��������á�������һ�Σ���ʱ��������Ӱһ���ӳ�����$N����ǰ��\n",
        "$nһʽ������׽Ӱ����ƮȻ���һ�ˣ��㿪$N���������ơ�\n",
        "$nһʽ��˳�缱�С������弱ת����Ϊһ���׹⣬��ò����ĳ�����$N����Χ��\n",
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
        if ((int)me->query("qi") < 45)
                return notify_fail("�������̫���ˣ���������ɽ����\n");

        me->receive_damage("qi", 35);
        return 1;
}

