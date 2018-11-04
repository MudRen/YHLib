// ITEM Made by player(Ëï¾ı:sunjun) /data/item/s/sunjun-guan.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Jul 26 13:11:38 2002
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m·ï[1;35m¹Ú[2;37;0m", ({ "guan" }));
	set_weight(2550);
	set("item_make", 1);
	set("unit", "¶¥");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¶¥Í·¿ø¡£
[1;36m´ËÄËµ±½ñ»ÊºóÓù´ÍµÄ·ï¹Ú£¬ÊÇ»Ê¹¬µÄÒ»´ó±¦Îï¡£[2;37;0m
Í·¿øÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºËï¾ı(sunjun)
");
	set("value", 2000000);
	set("point", 72);
	set("material", "stone");
	set("wear_msg", "[33m$N[33m×°±¸[1;31m·ï[1;35m¹Ú[2;37;0m[33m¡£[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁË[1;31m·ï[1;35m¹Ú[2;37;0m[33m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
