inherit SKILL;

string *dodge_msg = ({
	"$n���һ֧��ȫ�������һ�С����㵹�����������ܳ����࣬�����$N�Ĺ�����\n",
	"$n�����Ȼ�����޹ǣ�����ҡ�ڣ�ʹ��һ�С����ƯƼ�����ܹ���$N�Ĺ�����\n",
	"$nʹ�����ﻻ���ơ���������һ��ת����$N���Բ����������������$N���\n",
        "$nһ�С���Ҷ��硹��������һƬ��Ҷһ��Ʈ�˳�ȥ������֮������Ѹ�ٵ��˼�����\n"
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
        return notify_fail("�������̫���ˣ���������Ƽ��ˮ��\n");

    me->receive_damage("qi", 40);
    return 1;
}

