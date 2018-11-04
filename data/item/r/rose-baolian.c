// ITEM Made by player(ÓñÁáçç:rose) /data/item/r/rose-baolian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Apr  7 09:42:45 2003
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32mÆß²Ê±¦Á«[2;37;0m", ({ "baolian" }));
	set_weight(1530);
	set("item_make", 1);
	set("unit", "Ë«");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ë«ÌúÕÆ¡£
[1;32mÒ»¶äµ±ÄêÆĞÌáÀÏ×æ²ÉÕªµÄÆßÉ«Á«»¨[2;37;0m
ÌúÕÆÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÓñÁáçç(rose)
");
	set("value", 2000000);
	set("point", 210);
	set("material", "stone");
	set("wear_msg", "[33m$N[33m×°±¸[1;32mÆß²Ê±¦Á«[2;37;0m[33m¡£[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁË[1;32mÆß²Ê±¦Á«[2;37;0m[33m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/strike", 10);
	set("armor_prop/hand", 10);

	setup();
}

string long() { return query("long") + item_long(); }
