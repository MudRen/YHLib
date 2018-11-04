// ITEM Made by player(µ¶°Ô:bang) /data/item/b/bang-cloth.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Jul 14 17:06:08 2002
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32môä´ä³ñÉÀ[2;37;0m", ({ "cloth" }));
	set_weight(2400);
	set("item_make", 1);
	set("unit", "¼ş");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¼şÕ½ÒÂ¡£
Õ½ÒÂÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºµ¶°Ô(bang)
");
	set("value", 2000000);
	set("point", 127);
	set("material", "stone");
	set("wear_msg", "[33m$N[33m×°±¸[1;32môä´ä³ñÉÀ[2;37;0m[33m¡£[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁË[1;32môä´ä³ñÉÀ[2;37;0m[33m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
