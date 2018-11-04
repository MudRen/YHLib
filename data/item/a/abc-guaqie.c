// ITEM Made by player(Ğ¡¹Ï:abc) /data/item/a/abc-guaqie.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon May 06 14:05:17 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("¹ÏÇĞ[2;37;0m", ({ "guaqie" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[2;37;0m[33mÎÚ½ğ¿ó[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
´Ë½£Ò»¿´Òì³£·æÀû£¬ÊÇ°ÑÇĞ¹ÏµÄºÃ½£¡£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºĞ¡¹Ï(abc)
");
	set("value", 1200000);
	set("point", 68);
	set("material", "stone");
	set("wield_msg", "[1;36m$N[1;36mÒ»ÉùÇåĞ¥£¬¶¶³öÒ»±ú[1;36m$n[1;36m¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
