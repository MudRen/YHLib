// ITEM Made by player(Ğ¡°ü×Ó:cangku) /data/item/c/cangku-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Jan 14 13:39:07 2003
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[34mÄ©ÈÕµÄÉóÅĞ[2;37;0m", ({ "sword" }));
	set_weight(6750);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[37m¾«Ìú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[1;33m¿´ÉÏÈ¥Ö»¸Ğ¾õÑÛÇ°ÃÔÂÒ£¬ÊÓÏßÄ£ºı¡£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºĞ¡°ü×Ó(cangku)
");
	set("value", 800000);
	set("point", 30);
	set("material", "iron");
	set("wield_msg", "[1;31m$NÄ¿¹âÈç½££¬Ò»ÕóÕó×¯ÑÏ³ÁÎÈµÄÉùÒô½¥½¥ÏìÆğ£¬É²ÄÇ¼äÌìµØ±äÉ«£¬½­º£¿ñÏø¡£\n[1;33mµ±Ä©ÈÕµ½À´µÄÊ±ºò£¬ÎÒ½«×Ô¼ºÓëÎÒµÄµĞÈËÖÁÓÚÕıÒåµÄÌìÆ½ÉÏ£¬½ÓÊÜÔ¶¹ÅÖîÉñµÄ²Ã¾ö¡£\n[1;32mÕıÒåµÄÈË£¬ÄãµÄÁé»ê½«µÃµ½×îÖÕµÄ¿íË¡¡£[2;37;0m\n");
	set("unwield_msg", "[34mĞ°¶ñµÄÈË£¬ÄãµÄ½«ÊÜµ½×îÖÕµÄÉóÅĞ¡£\n[1;31mÈâÌå½«ÔÚ»ğÉñµÄÅØÏøÖĞ»ÙÃğ£¬ÄãµÄÁé»ê½«ÔÚ³Á¼ÅÖ®º£½ÓÊÜ×îÖÕµÄÍ´¿àÓë¼ÅÄ¯¡£\n[35mÉùÒô½¥½¥Íê½á£¬ÑÛÇ°µÄÒ»ÇĞ£¬½¥½¥¿ªÊ¼±ä»¯£¬ÄãµÄÊÓÏßÒ²½¥½¥Ä£ºı¡­¡­[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
