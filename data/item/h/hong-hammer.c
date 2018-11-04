// ITEM Made by player(ºìº¢¶ù:hong) /data/item/h/hong-hammer.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Oct 20 23:10:42 2002
#include <ansi.h>
#include <weapon.h>

inherit HAMMER;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36mÑµÁ·ÖØ´¸[2;37;0m", ({ "hammer" }));
	set_weight(15750);
	set("item_make", 1);
	set("unit", "°Ñ");
	set("long", "ÕâÊÇÓÉ[37m¾«Ìú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»°Ñ´¸¡£
´¸±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ººìº¢¶ù(hong)
");
	set("value", 800000);
	set("point", 30);
	set("material", "iron");
	set("wield_msg", "[1;36m$N[1;36mÒ»ÉùÇåĞ¥£¬¶¶³öÒ»°Ñ[1;36m$n[1;36m¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_hammer(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
