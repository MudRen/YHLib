// ITEM Made by player(������:starhand) /data/item/s/starhand-zhanyi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Mar 24 10:31:11 2003
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("ս��[2;37;0m", ({ "zhanyi" }));
	set_weight(2400);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ��ս�¡�
[1;33mս��[2;37;0m
ս��Ե�Ͽ���һ��С�֣�������(starhand)
");
	set("value", 2000000);
	set("point", 138);
	set("material", "stone");
	set("wear_msg", "[33m$N[33mװ��ս��[2;37;0m[33m��[2;37;0m\n");
	set("remove_msg", "[33m$N[33m������ս��[2;37;0m[33m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
