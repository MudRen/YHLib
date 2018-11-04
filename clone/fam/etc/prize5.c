#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR "���}Ѫ��" NOR, ({ "god blood", "god", "blood" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIR "�@��һƿ���}Ѫ�壬�ƺ�������á�\n" NOR);
                set("unit", "ƿ");
                set("value", 300000);
        }
        setup();
}

void init()
{
        add_action("do_drink", "drink");
}

int do_drink(string arg)
{
        object me = this_player();

        string mapsk;
        int na, un;
        mapping my = me->query_entire_dbase();

        na = query("name");
        un = query("unit");

        if (! arg || ! id(arg))
                return notify_fail("��Ҫ��ʲô������\n");

        if (me->is_busy())
                return notify_fail("��ʲô��С�ı�ҭ���ˡ�\n");

        my = me->query_entire_dbase();

        message_vision(HIY "$N" HIY "һ��������һ��" + un + na +
                       HIY "���£���Ҳ�о������κ�ƣ����\n" NOR, me);

        my["jing"]     = my["max_jing"];
        my["qi"]       = my["max_qi"];
        my["eff_jing"] = my["max_jing"];
        my["eff_qi"]   = my["max_qi"];
        my["neili"]    = my["max_neili"];
        my["jingli"]   = my["max_jingli"];

        me->start_busy(3);
        destruct(this_object());
        return 1;
}

int query_autoload()
{
        return 1;
}
