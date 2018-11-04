#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name(NOR + YEL "���Ͻ�" NOR,({ "houbei dao", "houbei", "dao", "blade" }) );
        set_weight(4800);
        if (clonep())
                destruct(this_object());
        else {
                set("long", YEL "����һ�����Ͻ���Ե������측���ŵ���ɫ��"
                            "����\n" NOR);
                set("unit", "��");
                set("value", 800000);
                set("no_sell", 1);
                set("material", "steel");
                set("wield_msg", YEL "$N" YEL "һ����Х����ৡ���һ�������"
                                 "���Ͻ𵶣�һ�ɺ�������ӿ����\n" NOR);
                set("unwield_msg", YEL "$N" YEL "���һ���������к��Ͻ�"
                                 "��ر���\n" NOR);
                set("stable", 100);
        }
        init_blade(140);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;

        if (me->query_skill_mapped("blade") != "bagua-dao" ||
            me->query_skill("bagua-dao", 1) < 100)
                return damage_bonus / 2;

        switch (random(12))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("blade") / 10 + 2);
                return YEL "$N" YEL "һ����ȣ����к��Ͻ𵶰��հ��Է�λ��"
                       "��ն��������һ������â���Ƶ�$n" YEL "�������ˣ�\n"
                       NOR;

        case 1:
                n = me->query_skill("blade");
                victim->receive_damage("qi", n * 3 / 4, me);
                victim->receive_wound("qi", n * 3 / 4, me);
                return YEL "$N" YEL "���к��Ͻ𵶰��հ��Է�λ����ն����$n"
                       YEL "����Χ��Ӱ�������Լ���£�����ɵ�����η\n�壬ֻ�ܹ�"
                       "��ǿ�����ֵ���\n" NOR;
        }
        return damage_bonus;
}
