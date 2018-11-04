// ITEM Made by player(Ê®¶Î:worua) /data/item/w/worua-woruab.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Apr  2 21:43:05 2003
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("Ò»¶Î½£[2;37;0m", ({ "woruab" }));
	set_weight(6750);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[37m¾«Ìú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÊ®¶Î(worua)
");
	set("value", 800000);
	set("point", 30);
	set("material", "iron");
	set("wield_msg", "Ìì[2;37;0m\n");
	set("unwield_msg", "ÏÂ[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
