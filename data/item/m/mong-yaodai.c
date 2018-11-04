// ITEM Made by player(ÄÉÀ¼:mong) /data/item/m/mong-yaodai.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Sep 24 07:18:18 2002
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36mÑü´ø[2;37;0m", ({ "yaodai" }));
	set_weight(960);
	set("item_make", 1);
	set("unit", "Ìõ");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»ÌõÑü´ø¡£
ÕâÊÇÒ»¼şÌìÇàÉ«[1;36mÑü´ø[2;37;0m£¬ÈáÈíµÄ±íÃæÉä³öÒ«ÑÛµÄ¹âÔó¡£ÕâÊÇ´«ËµÖĞµÄÖÁ±¦£º[1;36mÑü´ø[2;37;0m¡£[2;37;0m
Ñü´øÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÄÉÀ¼(mong)
");
	set("value", 2000000);
	set("point", 66);
	set("material", "stone");
	set("wear_msg", "$NÎûÎûÒ»Ğ¦£¬ÏµÉÏ[1;36mÑü´ø[2;37;0m¡£[2;37;0m\n");
	set("remove_msg", "$NÎûÎûÒ»Ğ¦£¬ÍÑÏÂ[1;36mÑü´ø[2;37;0m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
