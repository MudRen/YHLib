// ITEM Made by player(ºúĞĞ:qiangren) /data/item/q/qiangren-maozi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Feb 17 21:58:07 2003
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m´óºìÃ±[2;37;0m", ({ "maozi" }));
	set_weight(2550);
	set("item_make", 1);
	set("unit", "¶¥");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¶¥Í·¿ø¡£
Í·¿øÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ººúĞĞ(qiangren)
");
	set("value", 2000000);
	set("point", 97);
	set("material", "stone");
	set("wear_msg", "[33m$N[33m×°±¸[1;31m´óºìÃ±[2;37;0m[33m¡£[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁË[1;31m´óºìÃ±[2;37;0m[33m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
