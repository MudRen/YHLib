#include <ansi.h>
#include <weapon.h>

inherit CLUB;

void create()
{
	set_name(HIY "��ͭ��" NOR, ({"shutong gun", "shutong", "gun", "club"}));
	set_weight(2000);

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIY "һ��ʮ��������ͭ����\n" NOR);
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", HIY "$N" HIY "���ִ������һ����ͭ����\n" NOR);
		set("unwield_msg", HIY "$N" HIY "������һ�ۣ�����ͭ���������\n" NOR);
	}
	init_club(60);
	setup();
}
