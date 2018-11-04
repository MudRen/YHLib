// Ǭ��ʥˮ����ʥ������

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "Ǭ��ʥˮ" NOR, ({ "bless water", "water" }) );
	set_weight(30);

	if (clonep())
		set_default_object(__FILE__);
        else {
                set("long", HIW "һƿӨ��͸ʥˮ��ɢ���ѤĿ�Ĺ�ʡ�\n"
                            "����������ʥ����bless����������ߡ�\n" NOR);
                set("value", 1);
                set("no_sell", 1);
        	set("unit", "ƿ");
        }

        setup();
}

void init()
{
        if (this_player() == environment())
        {
                add_action("do_bless", "bless");
        }

}

int do_bless(string arg)
{
        object me;
        object ob;
        string msg;
        me = this_player();

        if (! arg || ! objectp(ob = present(arg, me)))
                return notify_fail("��Ҫʥ��ʲô��\n");

        if (ob == me)
                return notify_fail("���Գ�����\n");

        if (! ob->is_item_make())
                return notify_fail("��ֻ��ʥ�������������ߣ�\n");
        
        if (! stringp(ob->item_owner()) ||
              ob->item_owner() != me->query("id"))
                return notify_fail("��ֻ��ʥ���Լ��ı�������ߣ�\n");

        if (ob->query("bless") >= 30)
                return notify_fail("һ��������������ֻ��ʥ����ʮ�Σ�\n");

        message_vision(HIW "\n$N��Ǭ��ʥˮ��������" + ob->name() + HIW "�ϣ���̼�"
                       + ob->name() + HIW "�����һ�������һ�㣬ɢ����ѤĿ�Ĺ�ʣ�\n\n", me);
        ob->add("bless", 1);
        ob->set("consistence", 100);
        ob->add("stable", 1);

        msg = HIG "ͨ��ʥ�������" + ob->name() + "\n";
        msg += HIG "��̶ȵõ�������\n";
        msg += HIG "�;öȵõ�������\n";
        msg += HIG "����Ч���õ�������\n\n";

        tell_object(me, msg);

        destruct(this_object());
        ob->save();
        return 1;
}

int query_autoload()
{
         return 1;
}