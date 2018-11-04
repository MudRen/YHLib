#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$N����һ�ζ�����һ�С�С���꡹��˫�ƴ���һ���ȷ�����$n��ǰ��",
        "force" : 100,
        "attack": 25,
        "dodge" : 15,
        "parry" : 20,
        "damage": 10,
        "lvl"   : 0,
        "damage_type" : "����"
]),
([      "action" : "$N���λ���һ����������$n��ת��һ�С������ֻ֡���˫�ƻó�������Ӱ����$n",
        "force" : 130,
        "attack": 30,
        "dodge" : 10,
        "parry" : 15,
        "damage": 20,
        "lvl"   : 30,
        "damage_type" : "����"
]),
([      "action" : "$N�ֽ�һ����һ�С�����ŭ�š���˫������ǵذ�����$n��$l",
        "force" : 160,
        "attack": 45,
        "dodge" : 20,
        "parry" : 20,
        "damage": 25,
        "lvl"   : 60,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�ա�������硹��˫���ĳ��������磬��Ȼ����������Ϣ������$n��$l",
        "force" : 180,
        "attack": 50,
        "dodge" : 20,
        "parry" : 30,
        "damage": 30,
        "lvl"   : 80,
        "damage_type" : "����"
]),
([      "action" : "$N���һ����һ�С�������š���������޸���ɽ����һ���ȷ�������$n������",
        "force" : 210,
        "attack": 65,
        "dodge" : 25,
        "parry" : 20,
        "damage": 35,
        "lvl"   : 100,
        "damage_type" : "����"
]),
([      "action" : "$Nһ����Ц��һ�С����߾�ת��������һ��������һ�������ĳ����ֱ������޹ǣ��Ƶ���;����\n"
                   "��ű䣬����Ȱ�ӡ��$n��$l",
        "force" : 280,
        "attack": 95,
        "dodge" : 25,
        "parry" : 25,
        "damage": 45,
        "lvl"   : 120,
        "damage_type" : "����"
]),
([      "action" : "$N������ǰ��һ�С��ظ����硹��˫�������ĳ���һ���Ƴ��ǵĺ���������͸������$n��Χ�Ŀ�\n"
                   "����������",
        "force" : 320,
        "attack": 110,
        "dodge" : 30,
        "parry" : 30,
        "damage": 60,
        "lvl"   : 140,
        "damage_type" : "����"
]),
([      "action" : "$N����һ�������κ����������򣬷���ײ��$n��һ�С��Ʒ��´̡������罣��ֱ��$n������",
        "force" : 360,
        "attack": 135,
        "dodge" : 30,
        "parry" : 35,
        "damage": 75,
        "lvl"   : 160,
        "damage_type" : "����"
]),
([      "action" : "$Nһ���������������𣬰����һʽ��������β�������ֻ���$n��$l",
        "force" : 420,
        "attack": 150,
        "dodge" : 30,
        "parry" : 75,
        "damage": 90,
        "lvl"   : 180,
        "damage_type" : "����"
]),
([      "action" : "$N���һ���������嶾�񹦣�һ�С����������ɲ�Ǽ�ȫ��ë�����̣�һ�Ա��̵�˫צ�����ĳ�\n"
                   "$n��$lץȥ",
        "force" : 450,
        "attack": 185,
        "dodge" : 40,
        "parry" : 80,
        "damage": 120,
        "lvl"   : 200,
        "damage_type" : "ץ��"
])
});

int valid_enable(string usage)
{
        return usage=="hand" || usage=="parry";
}

int valid_learn(object me)
{

        if (me->query("character") == "��������")
                return notify_fail("�����а��룺��Ϊ�˹������䣬����ѧϰ���ֺ����书��\n");

        if (me->query("character") == "������")
                return notify_fail("�����а��룺�ߣ������书��Ȼ���������������𺦼���ѧ�����ã�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("��ǧ�����ֱ�����֡�\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ���򲻹����޷���ϰǧ�����֡�\n");

        if ((int)me->query("max_neili") < 1000)
                return notify_fail("�������̫�����޷���ϰǧ�����֡�\n");

        if ((int)me->query_skill("hand", 1) < 80)
                return notify_fail("��Ļ����ַ���򲻹����޷���ǧ�����֡�\n");

        if ((int)me->query_skill("hand", 1) < (int)me->query_skill("qianzhu-wandushou", 1))
                return notify_fail("��Ļ����ַ�ˮƽ���ޣ��޷����������ǧ�����֡�\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("qianzhu-wandushou",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;

        lvl  = me->query_skill("qianzhu-wandushou", 1);
        flvl = me->query("jiali");
        if (lvl < 80 || flvl < 10 || ! damage_bonus)
                return;

        if (flvl * 2 + random(lvl) > victim->query_skill("force") &&
            victim->affect_by("qianzhu_wandushou",
                              ([ "level" : flvl + random(flvl),
                                 "id"    : me->query("id"),
                                 "duration" : lvl / 50 + random(lvl / 20) ])))
        {
                return HIB "$n" HIB "��Ȼ�е�һ��Ī���Ķ��ģ��������ģ�ȫ���ʱ̱��\n" NOR;
        }
}

int practice_skill(object me)
{
        return notify_fail("ǧ������ֻ��ͨ����ȡ����Ķ�����������ߡ�\n");
}

string perform_action_file(string action)
{
        return __DIR__"qianzhu-wandushou/" + action;
}
