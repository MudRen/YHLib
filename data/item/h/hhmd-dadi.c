// ITEM Made by player(������:hhmd) /data/item/h/hhmd-dadi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Jun 29 20:44:38 2002
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[33m���[2;37;0m", ({ "dadi" }));
	set_weight(2400);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ��ս�¡�
һƬһ���޼ʵ�[33m���[2;37;0m
ս��Ե�Ͽ���һ��С�֣�������(hhmd)
");
	set("value", 2000000);
	set("point", 153);
	set("material", "stone");
	set("wear_msg", "[33m$N[33mװ��[2;37;0m[33m���[2;37;0m[33m��[2;37;0m\n");
	set("remove_msg", "[33m$N[33m������[2;37;0m[33m���[2;37;0m[33m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
