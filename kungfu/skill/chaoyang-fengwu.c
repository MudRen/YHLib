inherit SKILL;

string *dodge_msg = ({
        "$nһ�������񳯷��Ծ�����ߣ������$N��һ�С�\n",
        "$n�������һ�ݣ�ʹ��һ�С��������衹���ܹ���$N�Ĺ�����\n",
        "$nʹ�������ﳯ��������ǰԾ��������ǡ�ö����$N�Ĺ��ơ�\n",
        "$nһ�С�������졹������һչ����̬����ض��˿�ȥ��\n"
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
                return notify_fail("�������̫���ˣ��������������衣\n");

        me->receive_damage("qi", 40);
        return 1;
}
