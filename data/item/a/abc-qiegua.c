// ITEM Made by player(Ğ¡¹Ï:abc) /data/item/a/abc-qiegua.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Apr 28 11:58:58 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("ÇĞ¹Ï½£[2;37;0m", ({ "qiegua" }));
	set_weight(6750);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[37m¾«Ìú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
´Ë½£Ò»¿´Òì³£·æÀû£¬ÓÃÀ´ÇĞ¹Ï¿Ï¶¨²»´í¡£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºĞ¡¹Ï(abc)
");
	set("value", 800000);
	set("point", 39);
	set("material", "iron");
	set("wield_msg", "[1;36m$N[1;36mÒ»ÉùÇåĞ¥£¬¶¶³öÒ»±ú[1;36m$n[1;36m¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
