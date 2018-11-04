// ITEM Made by player(ÉÌ¼×:rara) /data/item/r/rara-fly.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Dec  6 22:22:42 2002
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m·ÉÁú[2;37;0m", ({ "fly" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "°Ñ");
	set("long", "ÕâÊÇÓÉ[1;35mÉñÌú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»°Ñµ¶¡£
µ¶±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÉÌ¼×(rara)
");
	set("value", 2200000);
	set("point", 191);
	set("material", "magic stone");
	set("wield_msg", "[1;36m$N[1;36mÒ»ÉùÇåĞ¥£¬¶¶³öÒ»°Ñ[1;36m$n[1;36m¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
