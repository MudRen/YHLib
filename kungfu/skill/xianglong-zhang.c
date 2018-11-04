#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N˫��ƽƽ�ᵽ��ǰ����ɫ���صĻ���ʩ���������лڡ�����$n",
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
([      "action" : "$Nʹ������ʮ����֮����Ծ��Ԩ������$n��$l�����ĳ�����",
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
([      "action" : "$N˫������ʹ������ʮ�����еġ�ʱ����������$n��������",
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
([      "action" : "$Nʹ������ʮ����һ�ơ��������ڡ���˫�������������$n��$l",
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
([      "action" : "ȴ��$N�Ż��󿪣����ʩ��һ�С���˪��������$n��$l��ȥ",
        "force"  : 660,
        "attack" : 200,
        "dodge"  : -20,
        "parry"  : 90,
        "damage" : 100,
        "damage_type": "����"
]),
([      "action" : "$N��Ŀ��ȣ�ʹ��������ެ����˫���������ϻ���$n��$l",
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

string main_skill() { return "xianglong-zhang"; }

mapping sub_skills = ([
        "kanglong-youhui"  : 150,        // 1
        "feilong-zaitian"  : 150,        // 2
        "jianlong-zaitian" : 150,        // 3
        "hongjian-yulu"    : 150,        // 4
        "qianlong-wuyong"  : 150,        // 5
        "lishe-dachuan"    : 150,        // 6
        "turu-qilai"       : 150,        // 7
        "zhenjing-baili"   : 150,        // 8
        "huoyue-zaiyuan"   : 150,        // 9
        "shuanglong-qushui": 150,        // 10
        "yuyue-yuyuan"     : 150,        // 11
        "shicheng-liulong" : 150,        // 12
        "miyun-buyu"       : 150,        // 13
        "sunze-youfu"      : 150,        // 14
        "longzhan-yuye"    : 150,        // 15
        "lvshuang-bingzhi" : 150,        // 16
        "diyang-chufan"    : 150,        // 17
        "shenlong-baiwei"  : 150,        // 18
]);

int get_ready(object me)
{
        return 1;
}

int get_finish(object me)
{
        if (me->query("character") == "���ռ�թ")
        {
                tell_object(me, "��������ϣ����ִ����Ʒ��ƺ����Լ����Ը�"
                                "���ϣ�����������\n");
                return 0;
        }

        if (me->query("gender") == "����")
        {
                tell_object(me, "��������ϣ�ֻ���������������������˹�֮"
                                "�¼������ʡ�\n");
                return 0;
        }

        if (me->query("str") < 36)
        {
                tell_object(me, "��������ϣ�ֻ���ֱ���������ʹ�ü���̧"
                                "��������\n");
                return 0;
        }

        if (me->query("con") < 32)
        {
                tell_object(me, "��������ϣ��;�����ǰ������ð��̫��Ѩͻ"
                                "ͻ������\n");
                return 0;
        }

        if ((int)me->query_skill("force") < 300)
        {
                tell_object(me, "��������ϣ��������ѣ����������ڹ�ˮƽ��"
                                "�д���ߡ�\n");
                return 0;
        }

        if ((int)me->query("max_neili") < 3000)
        {
                tell_object(me, "��������ϣ������᲻��������������Ӧ��"
                                "��������������\n");
                return 0;
        }

        if (random(30) <= 28)
        {
                tell_object(me, "���ʮ���Ƶİ����������򣬻�������������"
                                "�����ڻ��ͨ��\n");
                return 0;
        }

        tell_object(me, HIY "��һ���ǳɣ���ʮ���ƴ�ͷ��β������һ�䣬����"
                        "����ͨ\n���˽���ʮ���Ƶİ���裬�ڻ��ͨ����"
                        "���ľ�΢֮����\n��Ҳ�ǲ�ʹ����ô��ô�򵥡�\n" NOR);
        return 1;
}

mapping query_sub_skills()
{
        return sub_skills;
}

int valid_enable(string usage)
{
        return usage == "strike" || usage == "parry";
}  

int valid_learn(object me)
{
        if (me->query("character") == "���ռ�թ")
                return notify_fail("�����а��룺���书�����ý���ѧ��������\n");

        if ((int)me->query("str") < 36)
                return notify_fail("�����������������������������ʮ���ơ�\n");

        if ((int)me->query("con") < 32)
                return notify_fail("����������������������������ʮ���ơ�\n");

        if ((int)me->query_skill("force") < 300)
                return notify_fail("����ڹ���򲻹���������������ʮ���ơ�\n");

        if ((int)me->query("max_neili") < 3000)
                return notify_fail("���������Ϊ���㣬������������ʮ���ơ�\n");

        if ((int)me->query_skill("strike", 1) < 180)
                return notify_fail("��Ļ����Ʒ���򲻹���������������ʮ���ơ�\n");

        if ((int)me->query_skill("strike", 1) < (int)me->query_skill("xianglong-zhang", 1))
                return notify_fail("��Ļ����Ʒ�ˮƽ���ޣ�������������Ľ���ʮ���ơ�\n");

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

        cost = me->query_skill("xianglong-zhang", 1) / 5 + 90;

        if ((int)me->query("neili") < cost)
                return notify_fail("�����������������ʮ���ơ�\n");

        me->receive_damage("qi", 120);
        me->add("neili", -cost);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;

        lvl = me->query_skill("xianglong-zhang", 1);

        if (damage_bonus < 150 || lvl < 150) return 0;

        if (damage_bonus / 6 > victim->query_con())
        {
                victim->receive_wound("qi", (damage_bonus - 80) / 3, me);

                return random(2) ? HIR "ֻ��$n" HIR "ǰ�ء����꡹һ�����죬������"
                                   "�߹Ƕ��۵�������\n" NOR:

                                   HIR "$n" HIR "һ���ҽУ���ǰ���������꡹������"
                                   "�죬������Ѫ���硣\n" NOR;
        }
}

void skill_improved(object me)
{
        int i;
        string *sub_skillnames;

        sub_skillnames = keys(sub_skills);
        for (i = 0; i < sizeof(sub_skillnames); i++)
                me->delete_skill(sub_skillnames[i]);
}

string perform_action_file(string action)
{
        return __DIR__"xianglong-zhang/" + action;
}
