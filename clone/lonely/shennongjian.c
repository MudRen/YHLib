#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
        set_name(HIG "��ũ�" NOR,({ "shennong jian", "shennong", "jian", "staff" }) );
        set_weight(3800);
        if (clonep())
                destruct(this_object());
        else {
                set("long", HIG "һ��������ͨ��ҩ�������Ͽ��š���ũ�����֡�\n" NOR);
                set("unit", "��");
                set("value", 800000);
                set("no_sell", 1);
                set("material", "steel");
                set("wield_msg", HIG "$N" HIG "�γ���ũ�����������ܿ�����"
                                 "��ʱ����Ũ��Ĳ�ҩ��ζ��\n" NOR);
                set("unwield_msg", HIG "$N" HIG "����һЦ������ũ��ջء�\n" NOR);
                set("stable", 100);
        }
        init_staff(130);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        if (me->query_skill_mapped("staff") != "shennong-zhang" ||
            me->query_skill("shennong-zhang", 1) < 100)
                return damage_bonus / 2;

        switch (random(8))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("staff") / 12 + 2);
                return HIG "$N" HIG "��������ũﵼ��ٻ���ת����һ�ɴ̱ǵ���ζ"
                       "��ʱ���������$n" HIG "��״��æ���ˣ�\n" NOR;

        case 1:
                n = me->query_skill("staff");
                victim->receive_damage("qi", n * 2 / 3, me);
                victim->receive_wound("qi", n * 2 / 3, me);
                return HIG "$N" HIG "��������Ȱ�Ʈ����������ũ�һ�����裬��"
                       "��ǧ�ٸ����ƣ�$n" HIG "��״��������η�壬ֻ�ܹ���ǿ��"
                       "���ֵ���\n" NOR;
        }
        return damage_bonus;
}


