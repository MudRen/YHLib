// ITEM Made by player(ÂŞÀ¼:llan) /data/item/l/llan-whip.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Oct 12 20:55:21 2002
#include <ansi.h>
#include <weapon.h>

inherit WHIP;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[31m¾ÅÖİ¿ñÎè[2;37;0m", ({ "whip" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "¸ù");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¸ù±Ş¡£
ÕâÊÇÓÉÑÖÂŞ³ñÁ¶ÖÆ¶ø³ÉµÄ³¤±Ş¡£ÌìÏÂÎäÁÖÖĞ×îÀä¿áµÄÎäÆ÷¡£[2;37;0m
±Ş±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÂŞÀ¼(llan)
");
	set("value", 2000000);
	set("point", 132);
	set("material", "stone");
	set("wield_msg", "[31mÉ±ÁËÄã£¬ºÃÂğ£¿[2;37;0m\n");
	set("unwield_msg", "[31mÇë½èÏîÉÏÈËÍ·Ò»ÓÃ£¬ºÃÂğ£¿[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_whip(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
