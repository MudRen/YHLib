// ITEM Made by player(Ò¶Ğ¡îÎ:glassface) /data/item/g/glassface-kkk.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Aug  5 22:52:22 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("´òµ¹[2;37;0m", ({ "kkk" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[2;37;0m[33mÎÚ½ğ¿ó[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÒ¶Ğ¡îÎ(glassface)
");
	set("value", 1);
	set("point", 125);
	set("material", "stone");
	set("wield_msg", "[1;36m$N[1;36mÒ»ÉùÇåĞ¥£¬¶¶³öÒ»±ú[1;36m$n[1;36m¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
