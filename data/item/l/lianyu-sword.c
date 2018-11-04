// ITEM Made by player(Á¶Óü:lianyu) /data/item/l/lianyu-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Aug 20 11:23:42 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m±ÌÂÌ¶´óï[2;37;0m", ({ "sword" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[1;31mÌÒ»¨Ó°Âä·ÉÉñ½£[1;36m±Ìº£³±Éı°´Óñóï[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÁ¶Óü(lianyu)
");
	set("value", 2000000);
	set("point", 144);
	set("material", "stone");
	set("wield_msg", "[1;32mµ¯Ö¸·åÍ·ÑûÃ÷ÔÂ£¬ÇåÒô¶´ÄÚÌıÖñÓ°[2;37;0m\n");
	set("unwield_msg", "[1;32mÂÌÖñÁÖÍâñö»÷Óñ£¬ÊÔ½£Í¤ÄÚ×àÂÚÒô[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
