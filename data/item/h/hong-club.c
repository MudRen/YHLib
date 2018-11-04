// ITEM Made by player(ºìº¢¶ù:hong) /data/item/h/hong-club.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Oct 26 15:28:45 2002
#include <ansi.h>
#include <weapon.h>

inherit CLUB;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m³¤¹÷[2;37;0m", ({ "club" }));
	set_weight(6750);
	set("item_make", 1);
	set("unit", "¸ù");
	set("long", "ÕâÊÇÓÉ[37m¾«Ìú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¸ù¹÷¡£
¹÷±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ººìº¢¶ù(hong)
");
	set("value", 800000);
	set("point", 37);
	set("material", "iron");
	set("wield_msg", "[1;36m$N[1;36mÒ»ÉùÇåĞ¥£¬¶¶³öÒ»¸ù[1;36m$n[1;36m¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_club(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
