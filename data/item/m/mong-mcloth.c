// ITEM Made by player(ÄÉÀ¼:mong) /data/item/m/mong-mcloth.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Oct 12 19:08:15 2002
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36mµ­ÑÌĞã²Å×°[2;37;0m", ({ "mcloth" }));
	set_weight(2400);
	set("item_make", 1);
	set("unit", "¼ş");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¼şÕ½ÒÂ¡£
ÕâÊÇÒ»¼şÌìÇàÉ«Õ½ÒÂ£¬ÈáÈíµÄ±íÃæÉä³öÒ«ÑÛµÄ¹âÔó¡£ÕâÊÇ´«ËµÖĞµÄÖÁ±¦£º[1;36mµ­ÑÌĞã²Å×°[2;37;0m¡£[2;37;0m
Õ½ÒÂÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÄÉÀ¼(mong)
");
	set("value", 2000000);
	set("point", 169);
	set("material", "stone");
	set("wear_msg", "$NÀûË÷µÄ´©ÉÏ[1;36mµ­ÑÌĞã²Å×°[2;37;0m¡£[2;37;0m\n");
	set("remove_msg", "$NÀûË÷µÄÍÑÏÂ[1;36mµ­ÑÌĞã²Å×°[2;37;0m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
