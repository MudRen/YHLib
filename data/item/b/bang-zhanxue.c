// ITEM Made by player(µ¶°Ô:bang) /data/item/b/bang-zhanxue.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Oct 14 00:12:05 2002
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33mºì»¨Õ½Ñ¥[2;37;0m", ({ "zhanxue" }));
	set_weight(720);
	set("item_make", 1);
	set("unit", "Ë«");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ë«Ñ¥×Ó¡£
Ñ¥×ÓÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºµ¶°Ô(bang)
");
	set("value", 2000000);
	set("point", 60);
	set("material", "stone");
	set("wear_msg", "[33m$N[33m×°±¸[1;33mºì»¨Õ½Ñ¥[2;37;0m[33m¡£[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁË[1;33mºì»¨Õ½Ñ¥[2;37;0m[33m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/dodge", apply_armor() / 10 + 1);
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
