// ITEM Made by player(����:mdong) /data/item/m/mdong-swordb.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Oct  1 13:48:45 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m������[2;37;0m", ({ "swordb" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ������
�����Ͽ���һ��С�֣�����(mdong)
");
	set("value", 2000000);
	set("point", 157);
	set("material", "stone");
	set("wield_msg", "[1;33m$N৵ĳ��һ�������������У�������⵴�����������ˡ�[2;37;0m\n");
	set("unwield_msg", "[1;33m$N��������������������������������䡣[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
