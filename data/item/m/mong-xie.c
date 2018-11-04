// ITEM Made by player(ÄÉÀ¼:mong) /data/item/m/mong-xie.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Sep  5 09:25:00 2002
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36mÑ¥×Ó[2;37;0m", ({ "xie" }));
	set_weight(720);
	set("item_make", 1);
	set("unit", "Ë«");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ë«Ñ¥×Ó¡£
ÕâÊÇÒ»¼şÌìÇàÉ«Ñ¥×Ó£¬±íÃæÉä³öÒ«ÑÛµÄ¹âÔó¡£ÕâÊÇ´«ËµÖĞµÄÖÁ±¦£º[1;36mÑ¥×Ó[2;37;0m¡£[2;37;0m
Ñ¥×ÓÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÄÉÀ¼(mong)
");
	set("value", 2000000);
	set("point", 65);
	set("material", "stone");
	set("wear_msg", "$N·É¿ìµÄ´©ÉÏ[1;36mÑ¥×Ó[2;37;0m£¬µ²×¡Íà×ÓÉÏµÄÆÆ¶´¡£[2;37;0m\n");
	set("remove_msg", "$N·É¿ìµÄÍÑÏÂ[1;36mÑ¥×Ó[2;37;0m£¬Â¶³öÁËÍà×ÓÉÏµÄÆÆ¶´¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
