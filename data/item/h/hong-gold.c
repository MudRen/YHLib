// ITEM Made by player(ºìº¢¶ù:hong) /data/item/h/hong-gold.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Oct 26 20:14:56 2002
#include <ansi.h>
#include <weapon.h>

inherit XSWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0mÒ»Ç§Îå°ÙÁ½[33m»Æ½ğ[2;37;0m", ({ "gold" }));
	set_weight(1350);
	set("item_make", 1);
	set("unit", "Ö§");
	set("long", "ÕâÊÇÓÉ[37m¾«Ìú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ö§óï¡£
óï±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ººìº¢¶ù(hong)
");
	set("value", 800000);
	set("point", 30);
	set("material", "iron");
	set("wield_msg", "[1;36m$N[1;36mÒ»ÉùÇåĞ¥£¬¶¶³öÒ»Ö§[1;36m$n[1;36m¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_xsword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
