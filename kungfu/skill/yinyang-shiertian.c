// yinyang-shiertian.c ����ʮ������
// ��ʮ��֮ǰͨ�������񹦡������񹦡���ڤ�񹦡��貨΢����Ǭ
// ����Ų�ơ�����ʮ���ƺ������񽣣�����Ϊһ������S+++����ѧ��
// ����ʮ��������Լ���Ϊ�������е��书��
// Edit By Vin On 15/2/2001 

#include <ansi.h>

inherit FORCE;

string *xue_name = ({ 
"�͹�Ѩ", "����Ѩ", "����Ѩ", "��ԪѨ", "����Ѩ", "�м�Ѩ", "�н�Ѩ", "��ͻѨ", "�ٻ�Ѩ",
"����Ѩ", "����Ѩ", "���Ѩ", "�Ϲ�Ѩ", "��ԨѨ", "�쾮Ѩ", "��ȪѨ", "����Ѩ", "����Ѩ", });

string *attack_name = ({
"������������", "������������", "�����޼�����", "�����޼�����", });

string *dodge_msg = ({
        HIW "$n" HIW "�������һ�Σ�$N" HIW "��Ȼ�޷�������ֻ���Ա���\n" NOR,
        HIW "ֻ��$n" HIW "��������ζ���$N" HIW "��ǰ��ʱ������������$n" HIW
        "�Ļ�Ӱ����$N" HIW "��ȫ�޷������ʵ��\n" NOR,
        HIW "$n" HIW "���Ա�����бб������һ����ȴǡ����$N" HIW "�Ĺ���ʧ֮"
        "���塣\n" NOR,
        HIW "$N" HIW "��һ�����ĺÿ죬Ȼ��$n" HIW "һ�����ƺ����Ѱ��������"
        "ȴ��$N" HIW "��һ�иպñܿ���\n" NOR,
        HIW "����$n" HIW "����һԾ���Ѳ�������Ӱ��$N" HIW "���д󺧣�ȴ�ּ�"
        "$n" HIW "���籼��������֮���ɣ���������˼�����ǡ�\n" NOR,
});

string *parry_msg = ({
        HIW "$N" HIW "һ�л���$n" HIW "���ϣ�ȴ��$n" HIW "����Ǭ����Ų���ھ�"
        "������������������¡�\n" NOR,
        HIW "$n����һ����$N" HIW "�����Լ������ػ��������ŵ������˼�����\n" NOR,
        HIW "$n�ֱۻ�ת����$N" HIW "����������һ�ƣ�$N" HIW "������ա�\n" NOR,
        HIW "$n�����������$N" HIW "����������һ����$N" HIW "���Ʋ�ס��ֱ��ǰ��ȥ��\n" NOR,
        HIW "$n���β�����$N" HIW "һ�л��£�����ʯ���󺣣�������ס�ˡ�\n" NOR,
        HIW "$n��ǣ������$N" HIW "��������������ת�˺ü���Ȧ��\n" NOR,
        HIW "$n˫�ֻ�Ȧ��$N" HIW "ֻ����ǰ�������һ��ǽ����Ҳ������ȥ��\n" NOR,
        HIW "$n����һת��$N" HIW "һ�л��ڵ��ϣ�ֻ��ó������\n" NOR,
});

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("yinyang-shiertian", 1);
        return lvl * lvl * 15 * 40 / 100 / 200;
}

mapping *actionf = ({
([      "action": HIW "$N" HIW "������ָһ�����������񽣡���ǰ�̳��������ĵ�����"
                  "Ȼ���죬���ν���ֱָ$n" HIW,
        "force" : 700,
        "attack": 300,
        "dodge" : 450,
        "parry" : 450,
        "damage": 550,
        "weapon": HIW "�������ν���" NOR,
        "damage_type":  "����"
]),
([      "action": HIR "$N" HIR "����һ�࣬һ�����������һ�ɳ����ޱȵ�������ʱ��"
                  "��ӿ��$n" HIR "ȫ�����",
        "force" : 800,
        "attack": 400,
        "dodge" : 350,
        "parry" : 350,
        "damage": 250,
        "weapon": HIR "�����޼���" NOR,
        "damage_type":  "����"
]),
([      "action": HIY "$N" HIY "����һת��ȭͷЯ�ż�����ת�������ӳ����������磬"
                  "��������������$n" HIY,
        "force" : 800,
        "attack": 400,
        "dodge" : 350,
        "parry" : 350,
        "damage": 250,
        "weapon": HIY "�����޼���" NOR,
        "damage_type":  "����"
]),
([      "action": WHT "$N" WHT "˫��ƽƽ�ᵽ��ǰ����ɫ���صĻ���ʩ��������ʮ����"
                  "������$n" WHT "ȫ�����",
        "force" : 1000,
        "attack": 450,
        "dodge" : 200,
        "parry" : 200,
        "damage": 200,
        "weapon": WHT "�����޼���" NOR,
        "damage_type": "����"
]),
([      "action": HIW "$N" HIW "˫��ʮָ���죬��ʮ���������ٳ�Ѩ�м������������"
                  "���񽣡�������磬ָ��$n" HIW,
        "force" : 700,
        "attack": 300,
        "dodge" : 450,
        "parry" : 450,
        "damage": 550,
        "weapon": HIW "�������ν���" NOR,
        "damage_type":  "����"
]),
([      "action": WHT "$N" WHT "ͻȻ���η���˫�ƾӸ�����һ�С�����ʮ���ơ��ں�"
                  "Х����Ѹ���ޱȵ�����$n" WHT "ȫ�����",
        "force" : 1000,
        "attack": 450,
        "dodge" : 200,
        "parry" : 200,
        "damage": 200,
        "weapon": WHT "�����޼���" NOR,
        "damage_type": "����"
]),
});

mapping *actionw = ({
([      "action": HIY "$N" HIY "���ƺ��������裬$w" HIY "�仯�޳���׽��������$n"
                  HIY "������ȥ",
        "force" : 600,
        "attack": 300,
        "dodge" : 300,
        "parry" : 300,
        "damage": 400,
        "damage_type": "����"
]),
([      "action": HIY "$N" HIY "���е�$w" HIY "ͻ������ɭ�ϣ�����ǧ�������۶�"
                  "������ͬ����һ���ɨ$n" HIY,
        "force" : 600,
        "attack": 300,
        "dodge" : 300,
        "parry" : 300,
        "damage": 400,
        "damage_type": "����"
]),
([      "action": HIY "$N" HIY "�������е�$w" HIY "����������һ�����$n" HIY "��"
                  "�����ң�û�а���·�",
        "force" : 600,
        "attack": 300,
        "dodge" : 300,
        "parry" : 300,
        "damage": 400,
        "damage_type": "����"
]),
([      "action": HIY "$N" HIY "����$w" HIY "�û���һ��һ��ԲȦ���ƺ�Ҫ��$n" HIY
                  "���Ű�Χ",
        "force" : 600,
        "attack": 300,
        "dodge" : 300,
        "parry" : 300,
        "damage": 400,
        "damage_type": "����"
]),
([      "action": HIY "$N" HIY "��Ц��ת$w" HIY "������һָ���ĵ��黨ָ֮�⣬��"
                  "��$n" HIY "ȫ��",
        "force" : 600,
        "attack": 300,
        "dodge" : 300,
        "parry" : 300,
        "damage": 400,
        "damage_type": "����"
]),
});

string main_skill()
{
        return "yinyang-shiertian";
}

mapping sub_skills = ([
        "jiuyin-shengong"  : 250,
        "jiuyang-shengong" : 250,
        "six-finger"       : 250,
        "dragon-strike"    : 250,
        "lingbo-weibu"     : 250,
        "qiankun-danuoyi"  : 250,
        ]);

int get_ready(object me)
{
        return 1;
}

int get_finish(object me)
{
        object ob;

        tell_object(me, HIW "һ�󷲳�����ӿ����ͷ���㼸��������̾�����Ǽ䣬����ۻ��ף�����һ��Ī��\n"
                        "�ı�������ʦ̩�����ָ߳���ʤ������̩ɽ��С����֮����Ȼ��������ֻ������\n����"
                        "��ѧ���ڿ����Ƕ�ô����С��Ц��\n" NOR);
        return 1;
}

mapping query_sub_skills()
{
        return sub_skills;
}

string *usage_skills = ({ "unarmed", "strike", "claw", "hand", "cuff", "finger",
                          "sword", "blade", "hammer", "throwing", "club", "whip",
                          "staff", "dodge", "dagger", "parry", "force" });

int valid_enable(string usage)
{
        return (member_array(usage, usage_skills) != -1);
}

int valid_force(string force)
{
        return 1;
}

int double_attack()
{
        return 1;
}

mapping query_action(object me, object weapon)
{
        return weapon ? actionw[random(sizeof(actionw))] :
                        actionf[random(sizeof(actionw))];
}

string query_parry_msg(string limb)
{
        return parry_msg[random(sizeof(parry_msg))];
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
        int level;
        int i;

        for (i = 0; i < sizeof(usage_skills); i++)
                if (me->query_skill(usage_skills[i], 1) < level)
                        return notify_fail("���" + to_chinese(usage_skills[i]) + "����⻹"
                                           "�������޷������������������ʮ�����졣\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("����ʮ�����첩����޷��򵥵�ͨ����ϰ������\n");
}

int difficult_level()
{
        return 3000;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        string name1, name2, weapon;
        name1 = xue_name[random(sizeof(xue_name))];
        name2 = attack_name[random(sizeof(attack_name))];

        victim->receive_wound("qi", damage_bonus * 3, me);
        me->add("neili", me->query("jiali") / 3);

        if (victim->query("neili") < 500)
                victim->set("neili", 0);
        else
                victim->add("neili", -300);

        return NOR + HIR "$n" HIR "����$N" HIR "һ�У�" + name2 + "��ʱ�����"
               "�룬ȫ��������" + name1 + "��к������\n" NOR;
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mapping result;
        int ap, dp;

        ap = ob->query_skill("parry");
        dp = me->query_skill("yinyang-shiertian", 1);

        if (random(ap * 2 / 3) < dp * 3 / 2)
        {
                result = ([ "damage": -damage ]);

                switch (random(4))
                {
                case 0:
                        result += (["msg" : HIW "$n" HIW "�溬΢Ц������һ���ѽ���"
                                            "�����н�������ȫ��������\n" NOR]);
                        break;
                case 1:
                        result += (["msg" : HIW "$n" HIW "üͷ΢΢һ�壬��Ҳ��������"
                                            "$N" HIW "��һ�ߡ�\n" NOR]);
                        break;
                case 2:
                        result += (["msg" : HIW "$n" HIW "����΢΢һ�����ѽ�$N" HIW 
                                            "�����������⡣\n" NOR]);
                        break;
                default:
                        result += (["msg" : HIW "$n" HIW "һ����ߣ�����΢΢һ������"
                                            "ƮȻԶȥ��ʹ$N" HIW "�Ľ���ȫ���ô���\n" NOR]);
                        break;
                }
                return result;
        }
}

int query_effect_parry(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("yinyang-shiertian", 1);
        if (lvl < 200) return 100;
        if (lvl < 250) return 150;
        if (lvl < 350) return 180;
        return 200;
}

int query_effect_dodge(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("yinyang-shiertian", 1);
        if (lvl < 200) return 100;
        if (lvl < 250) return 150;
        if (lvl < 350) return 180;
        return 200;
}

string perform_action_file(string action)
{
        return __DIR__"yinyang-shiertian/perform/" + action;
}

string exert_function_file(string action)
{
        return __DIR__"yinyang-shiertian/exert/" + action;
}

