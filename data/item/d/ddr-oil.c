// ITEM Made by player(ÁªÏë:ddr) /data/item/d/ddr-oil.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jul 24 12:25:13 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33mÆÆÍ­[1;36mÀÃÌú[2;37;0m", ({ "oil" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
¿´£¬¿´Ê²Ã´¿´£¬ÔÙ¿´¾Í°ÑÄãºÈµô[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÁªÏë(ddr)
");
	set("value", 2000000);
	set("point", 90);
	set("material", "stone");
	set("wield_msg", "½õĞåÉ½ºÓ[2;37;0m\n");
	set("unwield_msg", "½õĞåÉ½ºÓ[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
