// ITEM Made by player(Øßáõ:yanrong) /data/item/y/yanrong-hand.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Jun 28 21:38:24 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36måĞ[1;37mÒ£[1;32mÖ¸[2;37;0m", ({ "hand" }));
	set_weight(1190);
	set("item_make", 1);
	set("unit", "Ì×");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ì×Ö¸Ì×¡£
[1;35mÉ¢·¢×Å¹ÅÆÓ¹âÔóµÄÓñ°ßÖ¸£¬Õâ±ãÊÇ[1;36måĞ[1;37mÒ£[1;32mÖ¸[2;37;0m¡£[2;37;0m
Ö¸Ì×ÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºØßáõ(yanrong)
");
	set("value", 2000000);
	set("point", 147);
	set("material", "stone");
	set("wear_msg", "$NÎ¢Î¢Ò»Ğ¦£¬ÇáÇá´÷ÉÏÒ»Ã¶[1;36måĞ[1;37mÒ£[1;32mÖ¸[2;37;0m£¬¶ÙÊ±Ö¸¼â¹â»ªËÄÉä¡£[2;37;0m\n");
	set("remove_msg", "$N½«[1;36måĞ[1;37mÒ£[1;32mÖ¸[2;37;0m´ÓÖ¸¼âÈ¡ÁËÏÂÀ´¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/finger", 10);
	set("armor_prop/claw", 10);

	setup();
}

string long() { return query("long") + item_long(); }
