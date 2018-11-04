// ITEM Made by player(ÄÉÀ¼:mong) /data/item/m/mong-xyj.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Oct 12 13:45:20 2002
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36måĞÒ£½í[2;37;0m", ({ "xyj" }));
	set_weight(2550);
	set("item_make", 1);
	set("unit", "¶¥");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¶¥Í·¿ø¡£
ÕâÊÇÒ»¼şÌìÇàÉ«Í·½í£¬ÈáÈíµÄ±íÃæÉä³öÒ«ÑÛµÄ¹âÔó¡£ÕâÊÇ´«ËµÖĞµÄÖÁ±¦£º[1;36måĞÒ£½í[2;37;0m¡£[2;37;0m
Í·¿øÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÄÉÀ¼(mong)
");
	set("value", 2000000);
	set("point", 84);
	set("material", "stone");
	set("wear_msg", "$NÎ¢Î¢Ò»Ğ¦£¬ÓÃ[1;36måĞÒ£½í[2;37;0mÊø×¡ÁË×Ô¼ºµÄÍ··¢¡£[2;37;0m\n");
	set("remove_msg", "$NÇáÇáÒ»Ì¾£¬½â¿ªÁËÍ··¢ÉÏµÄ[1;36måĞÒ£½í[2;37;0m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
