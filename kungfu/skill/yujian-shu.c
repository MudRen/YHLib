#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$N���ƺ��������裬�������������������ɽ����Ϊһ������$n������ȥ",
        "force" : 20,
        "attack": 65,
        "dodge" : 65,
        "parry" : 60,
        "damage": 25,
        "lvl" : 21,
        "damage_type" : "����"
]),
([      "action" : "$N����ͻ������ɭ�ϣ�����ǧ�������۶��������ƻ���$n",
        "force" : 20,
        "attack": 70,
        "dodge" : 60,
        "parry" : 65,
        "damage": 30,
        "lvl" : 28,
        "damage_type" : "����"
]),
([      "action" : "$N�������ߣ�����һ��������һ������$nĪ������ֲ���$N��������ʵ",
        "force" : 180,
        "attack": 100,
        "dodge" : 70,
        "parry" : 105,
        "damage": 130,
        "lvl" : 105,
        "damage_type" : "����"
]),
([      "action" : "$N��������ת��$n����������µ���$n�̳�һ������֪ʹ����ʲô����",
        "force" : 210,
        "attack": 110,
        "dodge" : 75,
        "parry" : 95,
        "damage": 140,
        "lvl" : 112,
        "damage_type" : "����"
]),
([      "action" : "$NͻȻһ������$n��$l����һ��ȴ�����������ţ�$n�����޴룬��֪����Ǻ�",
        "force" : 230,
        "attack": 115,
        "dodge" : 90,
        "parry" : 95,
        "damage": 150,
        "lvl" : 119,
        "damage_type" : "����"
]),
([      "action" : "$N��Ю���ƣ��󿪴��ص��ҿ�һͨ�������нԻ���$n���Ƶ��������ȵ�$n���ò���",
        "force" : 250,
        "attack": 120,
        "dodge" : 95,
        "parry" : 95,
        "damage": 160,
        "lvl" : 126,
        "damage_type" : "����"
]),
([      "action" : "$N���ֺὣ����$n��$l���������������е�һ����������Ȼ���$n���Կ��彣������",
        "force" : 270,
        "attack": 125,
        "dodge" : 85,
        "parry" : 95,
        "damage": 170,
        "lvl" : 133,
        "damage_type" : "����"
]),
([      "action" : "$N�ٽ���ӣ�Ѹ���ޱȵص���$n��$l��ȴ���˿�������������ʲô��ʽ",
        "force" : 300,
        "attack": 130,
        "dodge" : 115,
        "parry" : 80,
        "damage": 180,
        "lvl" : 140,
        "damage_type" : "����"
]),
([      "action" : "$N����һ��ָ��$n���������$n���������ڣ��˵����������ף�����˼��",
        "force" : 330,
        "attack": 140,
        "dodge" : 95,
        "parry" : 100,
        "damage": 190,
        "lvl" : 147,
        "damage_type" : "����"
]),
});

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int valid_learn(object me)
{
        object ob;

        if( !(ob = me->query_temp("weapon"))
        ||   (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ�ѽ���������������\n");

        if (me->query("int") < 35)
                return notify_fail("������ʲ��㣬�޷�����������Ľ��⡣\n");

        if (me->query_skill("sword", 1) < me->query_skill("yujian-shu", 1))
                return notify_fail("��Ļ��������������ޣ��޷������������������\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("�������޷�ͨ���򵥵���ϰ����ߡ�\n");
}

string perform_action_file(string action)
{
        return __DIR__"yujian-shu/" + action;
}

