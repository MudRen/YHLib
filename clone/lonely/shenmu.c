#include <weapon.h>
#include <ansi.h>

inherit CLUB;

void create()
{
        set_name(HIG "�Ϻ���ľ" NOR, ({ "nanhai shenmu", "nanhai", "shenmu", "club" }) );
        set_weight(6000);
        if (clonep())
                destruct(this_object());
        else {
                set("long", HIG "������̰�ؽ��ݵ�ľ����������ͨ��ȴ��������һ�㣬��Ӳ�ޱȡ�\n" NOR);
                set("unit", "��");
                set("value", 800000);
                set("no_sell", "������ɹ�¸���Ҳ������Ǯ��");
                set("material", "steel");
                set("wield_msg", HIG "$N" HIG "�ó�һ��������̰�ؽ��ݵ�ľ���������С�\n" NOR);
                set("unwield_msg", HIG "$N" HIG "�����е��Ϻ���ľ�����Ȧ�ӣ���ر��ϡ�\n" NOR);
                set("stable", 100);
        }
        init_club(160);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        if (me->query_skill_mapped("club") != "jinyuan-gun"
           || me->query_skill("jinyuan-gun", 1) < 100)
                return damage_bonus / 2;

        switch (random(8))
        {
        case 0:
                n = me->query_skill("club");
                victim->receive_damage("qi", n, me);
                victim->receive_wound("qi", n, me);
                return HIG "$N" HIG "�粽��ǰ�������Ϻ���ľת�����֣�������磬�Ӷ�"
                       "������$n" HIG "ɨȥ��\n" NOR;
        }
        return damage_bonus;
}
