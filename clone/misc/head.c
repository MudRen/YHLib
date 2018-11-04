// head.c �Դ�

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;
inherit F_CUTABLE;
inherit F_SILENTDEST;

void eat_effect();
int is_head() { return 1; }

void create()
{
        set_name(NOR + RED "ͷ­" NOR, ({ "head" }));
        set_weight(1500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1);
                set("no_sell", "�ҵ��졭�⡭����Ҳ���������١��ٸ��أ�");
                set("food_supply", 10);
                set("food_remaining", 4);
                set("long", RED "����һ����Ѫ���ܵ��׼�����Ѫ������������\n" NOR);
        }
}

int set_from(object owner)
{
        apply_effect((: eat_effect :));
        set("owner_id",  owner->query("owner_id"));
        set("is_player", owner->query("is_player"));
        set("killed_by", owner->query("killed_by"));
        set("defeated_by", owner->query("defeated_by"));
        set("defeated_by_who", owner->query("defeated_by_who"));
        set("assist", owner->query("assist"));
        set("gender", owner->query("gender"));

        if (! stringp(owner->query("victim_name")))
        {
                set("name", "���õ���ͷ");
                owner->set("name", "���õ���ͷʬ��");
        } else
        {
                set("name", owner->query("victim_name") + "����ͷ");
                owner->set("name", "��ͷʬ��");
        }

        if (owner->query_temp("clawed_by_jiuyin"))
        {
                set_temp("clawed_by_jiuyin", 1);
                set("long", query("long") +
                            "�����Ȼ�����С��������һ̽���պÿ��Բ��롣\n");
        }

        set_name(NOR + RED + query("name") + NOR, ({ "head" }));
        return 1;
}

int do_cut(object me, string part)
{
        if (! query("food_remaining"))
                return 0;

        return ::do_cut(me, part);
}

int finish_eat()
{
        set_name(NOR + WHT "����ͷ" NOR, ({ "bone" }));
        set_weight(150);
        set("long", WHT "����һ����ɭɭ������ͷ��\n" NOR);
        return 1;
}

void eat_effect()
{
        object me;

        me = this_player();
        me->add("combat/eatman", 1);
        if (me->query("shen") > -1000)
                me->set("shen", -1000);
}
