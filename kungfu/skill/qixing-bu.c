#include <ansi.h>

inherit SKILL;

string *dodge_msg = ({
     "$nһʽ�����������衹�����㣬�Ų��ƣ�������������ˮ��ֱ�������ࡣ\n",
     "$nһʽ����������������Ȼһ������ȫ�����ض��У���ʱ������$N���������ơ�\n",
     "$nһʽ����ת���ǡ����㲻�����ֲ�̧��һת�ۼ���Ƶ���$N�����\n",
     "$nһʽ����Ӱ���١���һת��䣬����˷�Ʈ����������$n����Ӱ����$N�����޴롣\n",
     "$nһʽ����תǬ��������̤�㣬��תǬ������һ�Σ��㵽����Զ�ĵط���\n",
     "$nһʽ��ֱ�������������ڿ��У������������һ�㣬��$Nͷ���ڿն�����\n",
     "$nһʽ��ܽ�س�ˮ��������һ����ȫ��Ϊһ����Ӱ�����ĵش�$Nͷ��Ʈ�䡣\n",
     "$nһʽ�����ɨ��Ҷ��������ٿ�Ĵ�$N����ǰֱ�Ƶ����$N�ɴ������ۣ��������ԡ�\n",
     "$nһʽ����Ȼ���֡�������ٿ�Ĵ�$N����ǰƮ��������֮����\n",
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
      if((int)me->query("qi") < 40 )
           return notify_fail("�������̫���ˣ���������ת���ǲ���\n");

      if((int)me->query("neili") < 30 )
           return notify_fail("�������̫���ˣ���������ת���ǲ���\n");

      me->receive_damage("qi", 35);
      me->add("neill", -24);
      return 1;
}
