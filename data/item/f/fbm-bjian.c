// ITEM Made by player(¾øÇé½£Ä§:fbm) /data/item/f/fbm-bjian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Aug 28 13:04:40 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m±ùÀä[31mÄ§[34m½£[2;37;0m", ({ "bjian" }));
	set_weight(30000);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[2;37;0m[36mÌìÉ½ĞşÌú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[1;34mÕâÊÇÒ»°Ñ´ÓÌìÉ½Í¯ÀÏËûÂèÉíÉÏÍµµ½µÄĞ°½££¬Ò»¿´½£ÉÏÓĞºÃ´óµÄ[31mÑı[1;34mÆø¡£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º¾øÇé½£Ä§(fbm)
");
	set("value", 2200000);
	set("point", 130);
	set("material", "stone");
	set("wield_msg", "[1;34m±¦½£Í»È»Ò»ÏÂ×ÓÔÚÄãÉíÇ°³öÏÈ¡£¡£¡£ÍÛÑ½¡£¡£ÏÅËÀÈËÁË¡£¡£¡£[31mÑıÆø¡£¡£¡£¡£¡£¡£[2;37;0m\n");
	set("unwield_msg", "[32mÍ»È»Ò»ÏÂ×ÓÓĞÒ»´ó¶Ñ¶¾Æø³öÏÈ¡£¡£¡£½£ºÍ[31mÑıÆø[32mÈ«Ã»ÁË¡£¡£¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
