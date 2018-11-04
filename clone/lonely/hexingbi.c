#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
        set_name(HIR "���α�" NOR,({ "hexing bi", "hexing", "bi" }) );
        set_weight(800);
        if (clonep())
                destruct(this_object());
        else {
                set("long", HIR "һ֧ͨ���ɫ��ë�ʣ��ʺ��Σ�����ȥ�Ǽ�������\n" NOR);
                set("unit", "֧");
                set("value", 800000);
                set("no_sell", 1);
                set("material", "steel");
                set("wield_msg", HIR "$N" HIR "������ȡ��һ֧���α��������С�\n" NOR);
                set("unwield_msg", HIR "$N" HIR "һ����ߣ������к��αʷŻ����䡣\n" NOR);
                set("stable", 100);
        }
        init_dagger(100);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        if (me->query_skill_mapped("dagger") != "hexing-bifa" ||
            me->query_skill("hexing-bifa", 1) < 100)
                return damage_bonus / 2;

        switch (random(10))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("dagger") / 10 + 2);
                return HIR "$N" HIR "���к��αʼ���ת������$n" HIR "����Χס��\n" NOR;

        case 1:
                n = me->query_skill("dagger");
                victim->receive_damage("qi", n * 3 / 5, me);
                victim->receive_wound("qi", n * 3 / 5, me);
                return HIR "$N" HIR "һ��ŭ�ȣ����к��α��͵���������$n" HIR "��\n" NOR;
        }
        return damage_bonus;
}
