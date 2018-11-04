// ITEM Made by player(ĞÇ»ğ:again) /data/item/a/again-baojia.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Aug 15 02:45:08 2002
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m½ğË¿¼×[2;37;0m", ({ "baojia" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "ÕÅ");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»ÕÅ»¤¼×¡£
»¤¼×ÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºĞÇ»ğ(again)
");
	set("value", 2000000);
	set("point", 72);
	set("material", "stone");
	set("wear_msg", "[33m$N[33m×°±¸[1;32m½ğË¿¼×[2;37;0m[33m¡£[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁË[1;32m½ğË¿¼×[2;37;0m[33m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/parry", apply_armor() / 15 + 1);
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
