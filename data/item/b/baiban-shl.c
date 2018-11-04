// ITEM Made by player(°×°å:baiban) /data/item/b/baiban-shl.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Jul 21 17:24:34 2002
#include <ansi.h>
#include <weapon.h>

inherit WHIP;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37mÊÅË®Á÷[2;37;0m", ({ "shl" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "¸ù");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¸ù±Ş¡£
[1;31mºìºìºìºìºì
[1;34mºìµÄ¾ÍÏóÀÏËÄµÄÆ¨¹É[1;36m
ÕæµÄ£¿
²»ĞÅÄãÔÙÇÆÇÆ£¿
[1;33mĞÅÁË°É£¬ÕæÊÇµÄ[2;37;0m
±Ş±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º°×°å(baiban)
");
	set("value", 2000000);
	set("point", 111);
	set("material", "stone");
	set("wield_msg", "$NÄÃ³ö¶ş°ÙÁã¶şÁ½»Æ½ğ¸ø»¨ÂúµØ[2;37;0m\n");
	set("unwield_msg", "[1;37m$N»º»ºµÄ´ÓË®³Ø³é³öÁËÁ¶ºÃµÄ±Ş¿´ÁË¿´£¬ÂúÒâµØËµ£¬ºÜºÃ£¬ºÜºÃ¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_whip(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
