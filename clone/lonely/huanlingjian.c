#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIW "���齣" NOR, ({ "huanling jian", "huanling", "sword" }));
        set_weight(4000);
        if (clonep())
                destruct(this_object());
        else {
                set("long", HIW "��������ϸ����ɢ���ŵ������⡣\n" NOR);
                set("unit", "��");
                set("value", 40000);
                set("no_sell", 1);
                set("material", "steel");
                set("wield_msg", HIW "���⻮�������齣������$N" HIW "���С�\n" NOR);

                set("unwield_msg", HIW "��غ�����$N" HIW "���еĻ��齣����Ȼ��û ��\n" NOR);
                set("stable", 100);
        }                                                                                                                    
        init_sword(100);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;

        if (me->query_skill_mapped("sword") != "xiaoyao-jian" ||
            me->query_skill("xiaoyao-jian", 1) < 120)
                return damage_bonus / 2;

        if (random(5) == 1)
        {
               n = me->query_skill("sword");
               victim->receive_damage("qi", n * 3 / 5, me);
               victim->receive_wound("qi", n * 2 / 7, me);
               return HIW "$N" HIW "һ����ߣ����л��齣��������һ�����߲�������ʱһ�����������⼤"
                      "�����������$n" HIW "��\n" NOR;
        }
        return damage_bonus;
}
