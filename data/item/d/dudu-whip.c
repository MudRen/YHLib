// ITEM Made by player(¶¾¶¾:dudu) /data/item/d/dudu-whip.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Sep 16 16:38:49 2002
#include <ansi.h>
#include <weapon.h>

inherit WHIP;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[30mºÚË÷[2;37;0m", ({ "whip" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "¸ù");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¸ù±Ş¡£
[30mÕâÊÇÒ»¸ùÆáºÚµÄ³¤±Ş£¬ºÁ²»ÆğÑÛ£¬µ«ÊÇÈëÊÖ³ÁÖØ£¬ÇÒ²»Ê§ÈáÈÍ£¬ÊµÔÚÊÇÇ§´¸°ÙÁ¶Ö®Îï¡£[2;37;0m
±Ş±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º¶¾¶¾(dudu)
");
	set("value", 2000000);
	set("point", 139);
	set("material", "stone");
	set("wield_msg", "[30m$NÒ»ÉìÊÖ£¬ÇÄÎŞÉùÏ¢µÄ½«ºÚË÷ÎÕÔÚÊÖÖĞ¡£[2;37;0m\n");
	set("unwield_msg", "[30m$N½«ÊÖÖĞµÄºÚË÷¾íÆğ£¬·Å»ØÑü¼ä¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_whip(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
