#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N˫��ƽƽ�ᵽ��ǰ����ɫ���صĻ���ʩ���������лڡ�����$n��$l",
        "force"  : 640,
        "attack" : 220,
        "dodge"  : 10,
        "parry"  : 100,
        "damage" : 130,
        "damage_type": "����"
]),
([      "action" : "$NͻȻ���η���˫�ƾӸ�����һ�С��������졹����$n��$l",     
        "force"  : 580,
        "attack" : 200,
        "dodge"  : 5,
        "parry"  : 80,
        "damage" : 100,
        "damage_type": "����"
]),
([      "action" : "$N����һ�С����������Ѹ���ޱȵ�����$n��$l",
        "force"  : 520,
        "attack" : 150,
        "dodge"  : 40,
        "parry"  : 145,
        "damage" : 100,
        "damage_type": "����"
]),
([      "action" : "$N˫��ʩ��һ�С��轥��½�����������ŷ�������$n��$l",
        "force"  : 560,
        "attack" : 180,
        "dodge"  : 15,
        "parry"  : 130,
        "damage" : 110,
        "damage_type": "����"
]),
([      "action" : "$N���ƾ۳�ȭ״������һ�С�Ǳ�����á���������$n��$l",
        "force"  : 580,
        "attack" : 190,
        "dodge"  : 10,
        "parry"  : 130,
        "damage" : 90,
        "damage_type": "����"
]),
([      "action" : "$Nʩ��һ�С�����󴨡������Ʋ�������������$n��$l",
        "force"  : 550,
        "attack" : 150,
        "dodge"  : 20,
        "parry"  : 180,
        "damage" : 110,
        "damage_type": "����"
]),
([      "action" : "$Nʹ����ͻ�������������ƴӲ����ܵĽǶ���$n��$l�Ƴ�",
        "force"  : 520,
        "attack" : 160,
        "dodge"  : 40,
        "parry"  : 150,
        "damage" : 90,
        "damage_type": "����"
]),
([      "action" : "$N���һ����˫��ʹ�����𾪰��������һ�а����$n",
        "force"  : 690,
        "attack" : 220,
        "dodge"  : -10,
        "parry"  : 75,
        "damage" : 120,
        "damage_type": "����"
]),
([      "action" : "$Nʹ������Ծ��Ԩ������$n��$l��������",
        "force"  : 530,
        "attack" : 150,
        "dodge"  : 30,
        "parry"  : 140,
        "damage" : 140,
        "damage_type": "����"
]),
([      "action" : "$N���λ�����˫��ʹһ�С�˫��ȡˮ��һǰһ����$n��$l",
        "force"  : 560,
        "attack" : 170,
        "dodge"  : 50,
        "parry"  : 115,
        "damage" : 100,
        "damage_type": "����"
]),
([      "action" : "$Nʹ������Ծ��Ԩ�������η���˫�Ʋ���һ����$n��$l����",     
        "force"  : 550,
        "attack" : 185,
        "dodge"  : 30,
        "parry"  : 100,
        "damage" : 110,
        "damage_type": "����"
]),
([      "action" : "$N˫������ʹ����ʱ����������$n��������",
        "force"  : 570,
        "attack" : 180,
        "dodge"  : 50,
        "parry"  : 110,
        "damage" : 110,
        "damage_type": "����"
]),
([      "action" : "$Nʹ�������Ʋ��꡹�����Ʒ�ס$n����·������бб������$l",     
        "force"  : 560,
        "attack" : 170,
        "dodge"  : 15,
        "parry"  : 120,
        "damage" : 100,
        "damage_type": "����"
]),
([      "action" : "$Nʹ�����������ڡ���˫�������������$n��$l",
        "force"  : 590,
        "attack" : 175,
        "dodge"  : 15,
        "parry"  : 100,
        "damage" : 80,
        "damage_type": "����"
]),
([      "action" : "$N����һת��ͻȻ�۵�$n��ǰ��һ�С���ս��Ұ������$n��$l",     
        "force"  : 580,
        "attack" : 180,
        "dodge"  : 10,
        "parry"  : 95,
        "damage" : 110,
        "damage_type": "����"
]),
([      "action" : "$N�Ż��󿪣�һ�С���˪��������$n��$l��ȥ",
        "force"  : 660,
        "attack" : 200,
        "dodge"  : -20,
        "parry"  : 90,
        "damage" : 100,
        "damage_type": "����"
]),
([      "action" : "$Nʹ��������ެ����˫���������ϻ���$n��$l",
        "force"  : 520,
        "attack" : 160,
        "dodge"  : 40,
        "parry"  : 130,
        "damage" : 110,
        "damage_type": "����"
]),
([      "action" : "$N���ƻ��أ�����ʹһ�С�������β�����»ζ��Ż���$n��$l",     
        "force"  : 520,
        "attack" : 150,
        "dodge"  : 60,
        "parry"  : 120,
        "damage" : 80,
        "damage_type": "����"
]),
});

string main_skill() { return "dragon-strike"; }

mapping sub_skills = ([
        "kanglong-youhui"  : 80,        // 1
        "feilong-zaitian"  : 80,        // 2
        "jianlong-zaitian" : 80,        // 3
        "hongjian-yulu"    : 80,        // 4
        "qianlong-wuyong"  : 80,        // 5
        "lishe-dachuan"    : 80,        // 6
        "turu-qilai"       : 80,        // 7
        "zhenjing-baili"   : 80,        // 8
        "huoyue-zaiyuan"   : 80,        // 9
        "shuanglong-qushui": 80,        // 10
        "yuyue-yuyuan"     : 80,        // 11
        "shicheng-liulong" : 80,        // 12
        "miyun-buyu"       : 80,        // 13
        "sunze-youfu"      : 80,        // 14
        "longzhan-yuye"    : 80,        // 15
        "lvshuang-bingzhi" : 80,        // 16
        "diyang-chufan"    : 80,        // 17
        "shenlong-baiwei"  : 80,        // 18
]);

int get_ready(object me)
{
        return 1;
}

int get_finish(object me)
{
        if (me->query("str") < 30 || me->query_str() < 45)
        {
                tell_object(me, "��������ϣ��ֱ�������������̧��������\n");
                return 0;
        }

        if (me->query("con") < 22 || me->query_con() < 37)
        {
                tell_object(me, "��������ϣ��;�����ǰ������ð��̫��Ѩͻͻ������\n");
                return 0;
        }

        if ((int)me->query_skill("force") < 150)
        {
                tell_object(me, "��������ϣ��������ѣ��Լ����ڹ�ˮƽ�������д���ߡ�\n");
                return 0;
        }

        if ((int)me->query("max_neili") < 1500)
        {
                tell_object(me, "��������ϣ������᲻��������������Ӧ�ü�������������\n");
                return 0;
        }

        if (random(10) < 5)
        {
                tell_object(me, "���ʮ���Ƶİ����������򣬻���������һ�ξ��ܹ��ڻ��ͨ��\n");
                return 0;
        }

        tell_object(me, HIY "��һ���ǳɣ���ʮ���ƴ�ͷ��β������һ�䣬���ж���ͨ\n"
                            "���˽���ʮ���Ƶİ���裬�ڻ��ͨ���Ʒ��ľ�΢֮����\n"
                            "��Ҳ�ǲ�ʹ����ô��ô�򵥡�\n" NOR);
        return 1;
}

mapping query_sub_skills()
{
        return sub_skills;
}

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }  

int valid_learn(object me)
{
        if ((int)me->query("str") < 31)
                return notify_fail("���������ӹǻ�������ʮ���ƣ�С��Ū���˸첲��\n");

        if ((int)me->query("con") < 24)
                return notify_fail("���˰ɣ���������ǲ��ã���ǿѧ�ˡ�\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ���򲻹����޷�ѧϰ����ʮ���ơ�\n");

        if ((int)me->query("max_neili") < 1500)
                return notify_fail("���������ô������ڻ��ͨ����ʮ���ƣ�\n");

        if ((int)me->query_skill("strike", 1) < 30)
                return notify_fail("��Ļ����Ʒ���򲻹����޷�ѧϰ����ʮ���ơ�\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("dragon-strike", 1))
                return notify_fail("��Ļ����Ʒ�ˮƽ���ޣ��޷���������Ľ���ʮ���ơ�\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        int cost;

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("������ʮ���Ʊ�����֡�\n");

        if ((int)me->query("qi") < 150)
                return notify_fail("�������̫���ˡ�\n");

        cost = me->query_skill("dragon-strike", 1) / 5 + 90;
        if ((int)me->query("neili") < 100)
                return notify_fail("�����������������ʮ���ơ�\n");

        me->receive_damage("qi", 120);
        me->add("neili", -cost);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"dragon-strike/" + action;
}

void skill_improved(object me)
{
        int i;
        string *sub_skillnames;

        sub_skillnames = keys(sub_skills);
        for (i = 0; i < sizeof(sub_skillnames); i++)
                me->delete_skill(sub_skillnames[i]);
}
