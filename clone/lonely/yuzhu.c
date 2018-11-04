#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
        set_name(HIG "������" NOR, ({ "yuzhu zhang", "yuzhu", "zhang" }));
        set_weight(26000);
        if (clonep())
                destruct(this_object());
        else {
                set("long", HIG "����һ���������Ƶ��ȣ�����ؤ��������"
                            "���İ������\n" NOR);
                set("unit", "��");
                set("value", 800000);
                set("no_sell", "����ɶ������ɹ�·��ģ�\n");
                set("material", "steel");
                set("wield_msg", HIG "$N" HIG "�ӱ�����һ����������"
                                 "�����ȣ�������˸�Ȧ�ӡ�\n" NOR);
                set("unwield_msg", HIG "$N" HIG "΢΢һЦ�������е���"
                                 "���Ȳ�ر���\n" NOR);
                set("stable", 100);
        }
        init_staff(180);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        if (me->query_skill_mapped("staff") != "dagou-bang"
           || me->query_skill("dagou-bang", 1) < 100)
                return damage_bonus / 2;

        switch (random(6))
        {
        case 0:
                n = me->query_skill("staff");
                victim->receive_damage("qi", n, me);
                victim->receive_wound("qi", n, me);
                return HIG "$N" HIG "������������һ�񣬵�ʱ�ó������Ӱ�����$n"
                       HIG "��ȥ��\n" NOR;
        }
        return damage_bonus;
}
