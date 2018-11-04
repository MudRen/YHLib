// ITEM Made by player(ÉÌ¼×:rara) /data/item/r/rara-zhang.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Mar 25 13:10:26 2003
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("ÕÆÖĞ±¦[2;37;0m", ({ "zhang" }));
	set_weight(1530);
	set("item_make", 1);
	set("unit", "Ë«");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ë«ÌúÕÆ¡£
ÌúÕÆÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÉÌ¼×(rara)
");
	set("value", 2000000);
	set("point", 179);
	set("material", "stone");
	set("wear_msg", "[33m$N[33m×°±¸ÕÆÖĞ±¦[2;37;0m[33m¡£[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁËÕÆÖĞ±¦[2;37;0m[33m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/armor", 10);
	set("armor_prop/hand", 10);
	set("armor_prop/strike", 10);

	setup();
}

string long() { return query("long") + item_long(); }
