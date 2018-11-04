#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name(YEL "ˮ��Ͳ" NOR, ({"yan tong", "yan", "tong"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", YEL "����һ֧������ϲ����ˮ��Ͳ�����"
                            "����(fire)�����̡�\n" NOR);
		set("unit", "��");
		set("value", 100);
		set("material", "steel");
                set("wield_msg", "$N�������$n�������е���������\n");
                set("unwield_msg", "$N�����е�$n���˻�ȥ��\n");
	}
	init_staff(10);
        setup();
}

int init()
{
	add_action("do_fire", "fire");
}

int do_fire(string arg)
{	
	object me = this_player();
	object ob = present("shui yan", me);

	if (arg != "yan" || ! arg)
		return notify_fail("��Ҫ��ʲô��\n");

        if (me->is_busy())
                return notify_fail("��������С�ı�Ǻ���ˡ�\n");

        if (! objectp(ob))
                return notify_fail("���Ѿ�û�����ˡ�\n");

	message_vision(HIW "$N" HIW "����ˮ��Ͳ���������˼��ڣ�����"
                       "���³�����ֻ���ľ���ö��ˡ�\n" NOR, me);
	me->add("jing", 50);
	if ((int)me->query("jing") > (int)me->query("max_jing") * 2)
	me->set("jing", (int)me->query("max_jing") * 2);
        me->start_busy(2);
	destruct(ob);

	return 1;
}

	