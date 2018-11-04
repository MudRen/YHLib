#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
        set_name(NOR + WHT "¹ͷ��" NOR,({ "lutou zhang", "lutou", "zhang" }) );
        set_weight(800);
        if (clonep())
                destruct(this_object());
        else {
                set("long", NOR + WHT  "һ���ֳ���ľ�ȣ��Ϸ���¹ͷ״��\n" NOR);
                set("unit", "��");
                set("value", 800000);
                set("no_sell", 1);
                set("material", "wood");
                set("wield_msg", WHT "$N" WHT "������¹ͷ���͵ػ��輸Ȧ��Ȼ���������С�\n" NOR);
                set("unwield_msg", WHT "$N" WHT "���һ������¹ͷ��ȡ�´��ڵ��ϡ�\n" NOR);
                set("stable", 100);
        }
        init_staff(100);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        if (me->query_skill_mapped("staff") != "lutou-zhang" ||
            me->query_skill("lutou-zhang", 1) < 100)
                return damage_bonus / 2;

        switch (random(10))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("staff") / 10 + 2);
                return WHT "$N" WHT "������¹ͷ�Ȼ���÷�������������$n" WHT "���֣�\n" NOR;

        case 1:
                n = me->query_skill("staff");
                victim->receive_damage("qi", n * 3 / 4, me);
                victim->receive_wound("qi", n * 3 / 4, me);
                return HIR "$N" HIR "�����������¹ͷ�ȴ�����£�����$n" HIR "��\n" NOR;
        }
        return damage_bonus;
}
