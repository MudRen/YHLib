#include <weapon.h>
#include <ansi.h>

inherit HAMMER;

void create()
{
        set_name(HIY "���½���" NOR, ({ "riyue jinlun", "riyue", "jinlun", "lun" }));
        set_weight(30000);
        if (clonep())
                destruct(this_object());
        else {
                set("long", HIY "���ַ�������������������ɽ���ͭ�������"
                            "������ɡ�\n" NOR);
                set("unit", "��");
                set("value", 800000);
                set("no_sell", 1);
                set("material", "steel");
                set("wield_msg", HIY "$N" HIY "�����½��ָ߾������У�����"
                                 "�ж�ʱ�߳�һ�ɺ�����\n" NOR);
                set("unwield_msg", HIY "$N" HIY "һ����Ц�������½����ջ�"
                                 "���С�\n" NOR);
                set("stable", 100);
        }
        init_hammer(180);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        if (me->query_skill_mapped("hammer") != "riyue-lun" ||
            me->query_skill("riyue-lun", 1) < 100)
                return damage_bonus / 2;

        switch (random(16))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("hammer") / 10 + 2);
                return HIY "��ʱ$N" HIY "�������½��ֻ�â���ǣ�������磬$n"
                       HIY "���ɵ�����һ�������ƶ�ʱ���ͣ�\n" NOR;

        case 1:
                n = me->query_skill("hammer");
                victim->receive_damage("qi", n * 3 / 4, me);
                victim->receive_wound("qi", n * 3 / 4, me);
                return HIY "$N" HIY "һ�����ȣ��������½��ֶ�Ȼ�������֣���"
                       "�����ͬ�ķ�λһ��Ϯ��$n" HIY "��\n" NOR;
        }
        return damage_bonus;
}
