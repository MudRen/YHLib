// ITEM Made by player(Ğ»Ïş·å:china) /data/item/c/china-dreamhat.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Oct 14 13:15:24 2002
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33mÃÔ»Ã¾­ÂÚ[2;37;0m", ({ "dreamhat" }));
	set_weight(2550);
	set("item_make", 1);
	set("unit", "¶¥");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¶¥Í·¿ø¡£
[1;33mÒ»¶¥½ğ»ÆÉ«µÄÃ±×Ó£¬ËÆºõ¾ßÓĞÄ³ÖÖÄ§Á¦¡£[2;37;0m
Í·¿øÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºĞ»Ïş·å(china)
");
	set("value", 2000000);
	set("point", 67);
	set("material", "stone");
	set("wear_msg", "[1;33m$N»º»º´øÉÏÃÔ»Ã¾­ÂÚ¡£\nö®Ê±Äã¾õµÃ$NÍğÈç»ÊµÛÒ»°ã£¬¶ÙÊ±Ë«Ï¥·¢Èí£¬ÈÌ²»×¡µ¹Í·±ã°İ£¬¿ÚÖĞ´óºô£º¡°Îá»ÊÍòËê£¬ÍòÍòËê£¡¡±\n[2;37;0m\n");
	set("remove_msg", "[1;33m$N»º»ºÕªÏÂÃÔ»Ã¾­ÂÚ¡£\n¡°°¡Ñ½¡±Ò»Éù£¬ÄãÌ±µ¹ÔÚµØ£¬à«à«×ÔÓïµÀ£º¡°ÎÒÃÎ¼û»ÊÉÏÀ²£¡¡±\n[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
