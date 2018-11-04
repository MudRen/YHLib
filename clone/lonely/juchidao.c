#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name(HIY "�ƽ��ݵ�" NOR, ({ "juchi dao", "juchi", "dao", "blade" }) );
        set_weight(6200);
        if (clonep())
                destruct(this_object());
        else {
                set("long", HIY "����һ�������б��Ļƽ��ݵ�����������"
                            "Ŀ�Ľ�⣬���гʾ��״��\n" NOR);
                set("unit", "��");
                set("value", 800000);
                set("no_sell", 1);
                set("material", "steel");
                set("wield_msg", HIY "$N" HIY "���һ�������ݵı�������ʱ"
                                 "ֻ������Ŀ��\n" NOR);
                set("unwield_msg", HIC "$N" HIC "������Х�����ип������ƽ�"
                                   "��ݵ���ص��ʡ�\n" NOR);
                set("stable", 100);
        }                                                                                                                    
        init_blade(120);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;

        if (me->query_skill_mapped("blade") != "yinyang-ren" 
           || me->query_skill("yinyang-ren", 1) < 100)
                return damage_bonus / 2;

        switch (random(12))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("blade") / 12 + 2);
                return HIC "\n$N" HIC "һ����ȣ����лƽ��ݵ�һ�񣬶�"
                       "ʱ���һ�����Ƶ�$n" HIC "�������ˣ�\n" NOR;

        case 1:
                n = me->query_skill("blade");
                victim->receive_damage("qi", n, me);
                victim->receive_wound("qi", n, me);
                return HIC "\n$N" HIC "�����лƽ��ݵ�������ǰ���͵ؽ�"
                      "��һ�ᣬ���ζ�֮��$n" HIC "ֻ��ɱ�����ˡ�\n" NOR;
        }
        return damage_bonus;
}
