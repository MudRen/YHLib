// ITEM Made by player(¾²²Æ:caishen) /data/item/c/caishen-yrjian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri May 17 19:22:20 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[37m°×ºç½£[2;37;0m", ({ "yrjian" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[1;37mÕâÊÇÒ»¿ÚÏ÷ÌúÈçÄàµÄ±¦½£¡£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º¾²²Æ(caishen)
");
	set("value", 2000000);
	set("point", 122);
	set("material", "stone");
	set("wield_msg", "[1;32m$N[1;31mÒ»ÉùÇåĞ¥£¬½«ÊÖÖĞ$n[1;31mÓÉÓÒÊÖ½»µ½×óÊÖ£¬¼òµ¥µÄ»®ÁËµÀ»¡Ïß£¬µ«ÆäÖĞÉ±ÆøÈ´ÈÃÄã¼¸ºõ´­²»¹ıÆøÀ´¡£[2;37;0m\n");
	set("unwield_msg", "[1;32m$N½«ÊÖÖĞ$n[1;32m»º»º·ÅÁËÏÂÀ´£¬ÄãÈ´»¹ÊÇÄÜ¸Ğµ½ËÄÉ¢µÄÉ±Æø¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
