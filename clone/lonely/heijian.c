#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(NOR + WHT "�ڽ�" NOR, ({ "hei jian", "jian", "hei", "sword" }));
        set_weight(6200);
        if (clonep())
                destruct(this_object());
        else {
                set("long", HIY "����һ����ɫ�ı���������������֮��������"
                            "ë���Ȼ��\n" NOR);
                set("unit", "��");
                set("value", 800000);
                set("no_sell", 1);
                set("material", "steel");
                set("wield_msg", HIY "$N" HIY "���һ����ɫ�ı������پ�������"
                               "�������ܡ�\n" NOR);
                set("unwield_msg", HIC "$N" HIC "��ת���ܣ��彣���ʣ���������"
                                   "����֮�С�\n" NOR);
                set("stable", 100);
        }                                                                                                                    
        init_sword(100);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;

        if (me->query_skill_mapped("sword") != "yinyang-ren" 
           || me->query_skill("yinyang-ren", 1) < 100)
                return damage_bonus / 2;   
              
        if(random(8) == 4)
        {
                n = me->query_skill("sword");
                victim->receive_damage("qi", n, me);
                victim->receive_wound("qi", n, me);
                return HIG "\n$N" HIG "̤ǰһ��������" HIB "�ڽ�" HIG 
                       "һ����ƽƽ�̳���$n" HIG "�پ�һ�ɺ��������"
                       "����\n" NOR;
        }
        return damage_bonus;
}
