// ITEM Made by player(¹íÉÕ:xdmlover) /data/item/x/xdmlover-xstrike.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Jun 16 09:36:38 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33mÀë»ğĞş±ùÕÆ[2;37;0m", ({ "xstrike" }));
	set_weight(1530);
	set("item_make", 1);
	set("unit", "Ë«");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ë«ÌúÕÆ¡£
ÌúÕÆÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º¹íÉÕ(xdmlover)
");
	set("value", 2000000);
	set("point", 122);
	set("material", "stone");
	set("wear_msg", "[33m$N[33m×°±¸[1;33mÀë»ğĞş±ùÕÆ[2;37;0m[33m¡£[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁË[1;33mÀë»ğĞş±ùÕÆ[2;37;0m[33m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/strike", 10);
	set("armor_prop/hand", 10);
	set("armor_prop/unarmed_damage", apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
