#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIY "��������" NOR, ({ "canyang baojian", "canyang", 
                                        "sword" }));
        set_weight(8000);
        if (clonep())
                destruct(this_object());
        else {
                set("long", HIY "
�˽�����ߣ�ϸ������ͨ�巺����⡣�����������Ͽ̲���ͼ
�ƣ�����֮�ϻ�����������������Ĺ�׭���ƺ�����ѧ�йء�\n" NOR);
                set("unit", "��");
                set("value", 800000);
                set("no_sell", 1);
                set("material", "steel");
                set("wield_msg", CYN "$N" CYN "���������Х����ʱ��"
                                 "âһ����һ������ƿջ���������$N"
                                 CYN "�Ƽ䡣\n" NOR);
                set("unwield_msg", CYN "$N" CYN "һ����ߣ������е�"
                                   "�����������뽣�ʡ�\n" NOR);
                set("skill", ([
                        "name"         : "poyang-jian",
                        "exp_required" : 300000,
                        "jing_cost"    : 90,
                        "difficulty"   : 92,
                        "max_skill"    : 129,
                        "min_skill"    : 60
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

        if (me->query_skill_mapped("sword") != "poyang-jian")
                return damage_bonus / 2;

        switch (random(4))
        {
        case 0:
                victim->receive_damage("jing", n / 2 , me);
                victim->receive_wound("jing", n / 4, me);
                return HIW "$N" HIW "��Хһ��������" HIY "��������" HIW 
                           "������ǰ���͵ػӳ���һ����ȵĽ�����$n" 
                           HIW "�Ƶ��������ˡ�\n" NOR;
        case 1:
                victim->receive_damage("qi", n, me);
                victim->receive_wound("qi", n, me);
                return HIR "$N" HIR "����" HIY "��������" HIR "ͻȻ����"
                           "һ����ҫ�۶�Ŀ��һ�����ȵĽ�������$n" HIR "��\n" NOR;
        }
        return damage_bonus;
}
