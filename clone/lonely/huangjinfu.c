#include <weapon.h>
#include <ansi.h>

inherit HAMMER;

#define ZHUJIAN    "/clone/lonely/book/zhujian1"

void create()
{
        set_name(NOR + YEL "�ƽ�" NOR, ({"huangjin fu", "huangjin", "fu"}));
        set_weight(20000);
        if (clonep())
                destruct(this_object());
        else {
                set("long", YEL "����һ�����������Ĵ󸫣�����ĩ���ƺ���Щ�ɶ���\n" NOR);
                set("unit", "��");
                set("value", 800000);
                set("no_sell", 1);
                set("material", "gold");
                set("wield_msg", YEL "$N" YEL "����һ�����������Ĵ󸫣����ֻ��������¡�\n" NOR);
                set("unwield_msg", YEL "$N" YEL "����һЦ�������еĻƽ��ջر���\n" NOR);
                set("stable", 100);
        }
        init_hammer(180);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        if (me->query_skill_mapped("hammer") != "leiting-fu"
           || me->query_skill("leiting-fu", 1) < 150)
                return damage_bonus / 2;

        switch (random(6))
        {
        case 0:
                n = me->query_skill("hammer");
                victim->receive_damage("qi", n, me);
                victim->receive_wound("qi", n, me);
                return YEL "$N" YEL "һ���Ϻȣ����лƽ���ʱ��â���ǣ�����һ����$n"
                       YEL "������ȥ��\n" NOR;
        }
        return damage_bonus;
}

void init()
{
        add_action("do_pick", "pick");
        add_action("do_pick", "turn");
}

int do_pick(string arg)
{
        object me, ob;
        me = this_player();

        if (! arg || ! id(arg))
                return 0;

        ob = find_object(ZHUJIAN);
        if (! ob) ob = load_object(ZHUJIAN);
        if (! environment(ob))
        {
                ob->move(me, 1);
                message_vision(HIC "$N" HIC "Ť�����������ָ����пգ����в�"
                               "��һ�����\n$N" HIC "��ʱ��ϲ��������æ��"
                               "֮ȡ�������뻳�С�\n" NOR, me);
                return 1;
        } else
	        return notify_fail(YEL "��Ť�����������ֱ��пտ���Ҳ��ʲô"
                                   "��û�С�\n" NOR);
}
