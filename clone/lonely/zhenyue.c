#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(NOR + CYN "�����з�" NOR, ({ "zhenyue shangfang", "zhenyue", 
                                              "shangfang", "sword" }));
        set_weight(8000);
        if (clonep())
                destruct(this_object());
        else {
                set("long", NOR + CYN "
�˽������������λ��ʮһ���Զ���������磬���彣����Ͷ
��������Ի�����з�������׭�飬�������ͨ�����⡣������
����֮�ϻ�����������������Ĺ�׭���ƺ�����ѧ�йء�\n" NOR);
                set("unit", "��");
                set("value", 800000);
                set("no_sell", 1);
                set("material", "steel");
                set("wield_msg", CYN "$N" CYN "���������Х����ʱ��"
                                 "âһ����һ������ƿջ���������$N"
                                 CYN "�Ƽ䡣\n" NOR);
                set("unwield_msg", CYN "$N" CYN "һ����ߣ������е�"
                                   "�����з��������뽣�ʡ�\n" NOR);
                set("skill", ([
                        "name"         : "zhenyue-jue",
                        "exp_required" : 300000,
                        "jing_cost"    : 80,
                        "difficulty"   : 80,
                        "max_skill"    : 149,
                        "min_skill"    : 50
                ]));
                set("stable", 100);
        }
        init_sword(140);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n = me->query_skill("sword");

        if (me->query_skill("sword") < 150)
                return damage_bonus / 2;

        if (me->query_skill_mapped("sword") != "henshan-jian"
           && me->query_skill_mapped("sword") != "zigai-jian"
           && me->query_skill_mapped("sword") != "furong-jian"
           && me->query_skill_mapped("sword") != "shilin-jian"
           && me->query_skill_mapped("sword") != "zhurong-jian"
           && me->query_skill_mapped("sword") != "tianzhu-jian"
           && me->query_skill_mapped("sword") != "wushen-jian")
                return damage_bonus / 2;

        switch (random(14))
        {
        case 0:
                victim->receive_damage("jing", n / 2, me);
                victim->receive_wound("jing", n / 4, me);
                return HIW "$N" HIW "����������" NOR + CYN "��"
                       "���з�" HIW "������ʱ��â���ǣ��Ƶ�$n"
                       HIW "�������ˣ�\n" NOR;
        case 1:
                victim->receive_damage("qi", n, me);
                victim->receive_wound("qi", n, me);
                return HIR "$N" HIR "����" NOR + CYN "�����з�"
                       HIR "��⵴����͸��һ��������Ľ���ֱ��$n"
                       HIR "��ȥ��\n" NOR;
        }
        return damage_bonus;
}
