// ITEM Made by player(Â³¶àÆÕ:loupdaube) /data/item/l/loupdaube-belt.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Nov 28 09:52:34 2002
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[35mÑü´ø[2;37;0m", ({ "belt" }));
	set_weight(960);
	set("item_make", 1);
	set("unit", "Ìõ");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»ÌõÑü´ø¡£
[35m£Ì£Ï£Õ£Ğ¡¡£Ä£§£Á£Õ£Â£Å[2;37;0m
Ñü´øÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÂ³¶àÆÕ(loupdaube)
");
	set("value", 2000000);
	set("point", 55);
	set("material", "stone");
	set("wear_msg", "[33m$N[33m×°±¸[2;37;0m[35mÑü´ø[2;37;0m[33m¡£[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁË[2;37;0m[35mÑü´ø[2;37;0m[33m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
