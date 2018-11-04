#include <ansi.h>

inherit SKILL;

mapping *action=({
([      "action" : "$Nһ��" HIY "�������ǬΪ���š�" NOR "���建���ζ���Χ��$n�������ƣ���Ȼ"
                   "Ѹ������б�����������ɻ��Σ�����$n��$l",
        "force" : 130,
        "attack": 21,
        "dodge" : 70,
        "parry" : 65,
        "damage": 14,
        "lvl"   : 0,
        "skill_name" : "�����ǬΪ����",
        "damage_type" : "����"
]),
([      "action" : "$Nһ��" WHT "���������Ϊ���š�" NOR "������������˫�Ʋ�ͣ�Ļ�������Ȼ��"
                   "��һ��������߸�Ծ������$n��$l����һ������",
        "force" : 170,
        "attack": 25,
        "dodge" : 83,
        "parry" : 76,
        "damage": 17,
        "lvl"   : 30,
        "skill_name" : "�������Ϊ����",
        "damage_type" : "����"
]),
([      "action" : "$Nһ��" YEL "���������Ϊ���š�" NOR "����������ˮ��Ʈ��������˫������Ʈ"
                   "������Ȼ����˫��զ�֣��ֱ�������������빥��$n",
        "force" : 190,
        "attack": 28,
        "dodge" : 95,
        "parry" : 88,
        "damage": 20,
        "lvl"   : 60,
        "skill_name" : "�������Ϊ����",
        "damage_type" : "����"
]),
([      "action" : "$Nһ��" HIW "���������Ϊ���š�" NOR "ٿ������$n��ǰ�������ո���ͷ������"
                   "�£��ƺ��Ե�û����ɣ�һ�����������������$n",
        "force" : 230,
        "attack": 35,
        "dodge" : 107,
        "parry" : 98,
        "damage": 23,
        "lvl"   : 90,
        "skill_name" : "�������Ϊ����",
        "damage_type" : "����"
]),
([      "action" : "$Nһ��" HIR "�������ӿ������š�" NOR "ͻȻ�������࣬ͷ�½��ϣ��������ӣ�"
                   "����һֻ�ڿ��������ķ�����һ������$n",
        "force" : 270,
        "attack": 40,
        "dodge" : 129,
        "parry" : 113,
        "damage": 27,
        "lvl"   : 120,
        "skill_name" : "�����ӿ�������",
        "damage_type" : "����"
]),
([      "action" : "$Nһ��" MAG "������Ӷ������š�" NOR "�������ݼ�ת��չ���ṦΧ��$n������"
                   "�ߣ���Ȼ�������һ������$n��$l",
        "force" : 320,
        "attack": 48,
        "dodge" : 154,
        "parry" : 118,
        "damage": 38,
        "lvl"   : 150,
        "skill_name" : "����Ӷ�������",
        "damage_type" : "����"
]),
([      "action" : "$N����ǰ��һ��" CYN "��������������š�" NOR "�������ȣ��Կ����������"
                   "һֻչ�᰿��Ĵ���������һԾ�Ѿ�����$n��������������\n��$n�Ĵ�׵Ѩ",
        "force" : 360,
        "attack": 61,
        "dodge" : 153,
        "parry" : 131,
        "damage": 45,
        "lvl"   : 180,
        "skill_name" : "�������������",
        "damage_type" : "����"
]),
([      "action" : "$N����һŤ�������Ŷ�׼$n��ʹ��һ��" HIM "�����̾��������š�" NOR "����$n"
                   "��γ��У�$N�ı�����������۾������ܼ�ʱ���ܣ���\nȻ$N��������$n�ؿڿ�ȥ��"
                   "˫��ͻȻ��Ҹ�������ֱ��$n��$l",
        "force" : 380,
        "attack": 73,
        "dodge" : 155,
        "parry" : 135,
        "damage": 57,
        "lvl"   : 220,
        "skill_name" : "���̾���������",
        "damage_type" : "����"
]),
});

int valid_enable(string usage)
{
        return usage == "strike" || usage == "parry";
}

string main_skill() { return "baihua-cuoquan"; }

int valid_learn(object me)
{
        if (me->query_skill("baihua-cuoquan", 1) > 0)
                return notify_fail("���Ѿ������˰ٻ���ȭ�������ٵ���ѧϰ�ˡ�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����������Ʊ�����֡�\n");

        if (me->query("max_neili") < 1200)
                return notify_fail("��������������޷���ϰ��������ơ�\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("bazhen-zhang", 1))
                return notify_fail("��Ļ����Ʒ�������ޣ��޷���������İ�������ơ�\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action)-1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("bazhen-zhang", 1);
        for (i = sizeof(action); i > 0; i--)
                if (level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 100 )
                return notify_fail("����������������Ϣһ�������ɡ�\n");

        if ((int)me->query("neili") < 80)
                return notify_fail("������������ˡ�\n");

        me->receive_damage("qi", 85);
        me->add("neili", -60);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"bazhen-zhang/" + action;
}
