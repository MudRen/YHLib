// ITEM Made by player(ÃçÒİ:kong) /data/item/k/kong-blade.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Dec  5 20:04:41 2002
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("¾«Ìúµ¶[2;37;0m", ({ "blade" }));
	set_weight(6750);
	set("item_make", 1);
	set("unit", "°Ñ");
	set("long", "ÕâÊÇÓÉ[37m¾«Ìú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»°Ñµ¶¡£
µ¶±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÃçÒİ(kong)
");
	set("value", 800000);
	set("point", 30);
	set("material", "iron");
	set("wield_msg", "[1;36m$N[1;36mÒ»ÉùÇåĞ¥£¬¶¶³öÒ»°Ñ[1;36m$n[1;36m¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
