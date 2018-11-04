// ITEM Made by player(����:dagou) /data/item/d/dagou-zhang.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Sep 16 08:03:43 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m������[2;37;0m", ({ "zhang" }));
	set_weight(4500);
	set("item_make", 1);
	set("unit", "˫");
	set("long", "������[1;37m����쾧[2;37;0m���ƶ��ɵ�һ˫���ơ�
����Ե�Ͽ���һ��С�֣�����(dagou)
");
	set("value", 4200000);
	set("point", 362);
	set("material", "tian jing");
	set("wear_msg", "[33m$N[33mװ��[1;32m������[2;37;0m[33m��[2;37;0m\n");
	set("remove_msg", "[33m$N[33m������[1;32m������[2;37;0m[33m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/strike", 10);
	set("armor_prop/hand", 10);

	setup();
}

string long() { return query("long") + item_long(); }
