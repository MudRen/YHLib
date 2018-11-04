// ITEM Made by player(Á¶Óü:lianyu) /data/item/l/lianyu-armor.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Oct  9 11:58:54 2002
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33mÁ¶Óü[1;32mÁÒ»ğ[2;37;0m", ({ "armor" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "ÕÅ");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»ÕÅ»¤¼×¡£
[1;37mÈıÊ®ÈıÌìÏÂÓĞµØ£¬µØÏÂÓĞ³Ç£¬³ÇÃû¹í³Ç£¬´óĞ¡ÑıÄ§£¬ÈËÉñĞóÉú¶¼ÔÚ´ËÂÖ»ØÍù·µ£¬Î½Ö®¡°[1;31mÁ¶Óü[1;37m¡±[2;37;0m
»¤¼×ÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÁ¶Óü(lianyu)
");
	set("value", 2000000);
	set("point", 122);
	set("material", "stone");
	set("wear_msg", "[33m$N[33m×°±¸[1;33mÁ¶Óü[1;32mÁÒ»ğ[2;37;0m[33m¡£[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁË[1;33mÁ¶Óü[1;32mÁÒ»ğ[2;37;0m[33m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
