// ITEM Made by player(Ğ¡¹Ï:abc) /data/item/a/abc-bbzy.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat May 18 09:03:25 2002
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m±Ì²¨Õ½ÒÂ[2;37;0m", ({ "bbzy" }));
	set_weight(2400);
	set("item_make", 1);
	set("unit", "¼ş");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¼şÕ½ÒÂ¡£
ÕâÊÇÒ»¼şÌÒ»¨µºµÄÕ½ÒÂ£¬ÉÏÃæ¿ÌÁË¾ÅÌõÉñÁú¡£[2;37;0m
Õ½ÒÂÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºĞ¡¹Ï(abc)
");
	set("value", 2000000);
	set("point", 133);
	set("material", "stone");
	set("wear_msg", "[33m$N[33m×°±¸±Ì²¨Õ½ÒÂ[2;37;0m[33m¡£[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁË±Ì²¨Õ½ÒÂ[2;37;0m[33m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
