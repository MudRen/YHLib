// chuanyun-bu ���Ʋ���


inherit SKILL;

string *dodge_msg = ({
    "$nһʽ��׷����硹�����ӳ���һת��$Nֻ������ǰһ����ʧȥ��Ŀ�ꡣ\n",
    "$nһʽ�����Ҵ�������˫�ŵ�أ�����ͻȻ�θ�����������Ʈ����$N���\n",
    "$nһʽ�����Ʋ��¡�������һ�Σ���ʱ��������Ӱһ���ӳ�����$N����ǰ��\n",
    "$nһʽ����Ӱ���١���ƮȻ���һ�ˣ��㿪$N���������ơ�\n",
    "$nһʽ������Ϊ�Ρ������弱ת����Ϊһ���׹⣬��ò����ĳ�����$N����Χ��\n",
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
        if( (int)me->query("qi") < 50 )
                return notify_fail("�������̫���ˣ����������Ʋ�����\n");

        me->receive_damage("qi", 40);
                return 1;
}

