// ITEM Made by player(Ãğ²Æ:caishen) /data/item/c/caishen-yuyi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Oct 20 10:00:28 2002
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m¿×È¸ÓğÒÂ[2;37;0m", ({ "yuyi" }));
	set_weight(2400);
	set("item_make", 1);
	set("unit", "¼ş");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¼şÕ½ÒÂ¡£
[1;37mÕâÊÇÒ»¼ş³ö×ÔÌì¹¬Ö¯Å®ÃîÊÖÉñ²ÃµÄÓğÉ´ÇáÒÂ¡£¿îÊ½ĞÂÓ±±ğÖÂÇáÈáÆ®ÒİµÄ¡£·ÅÔÚÊÖÖĞ¼òÖ±ÇáÈôÎŞÎï£¬ÕæÊÇÒ»¼ş·şÊÎ¼«Æ·¡£[2;37;0m
Õ½ÒÂÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÃğ²Æ(caishen)
");
	set("value", 2000000);
	set("point", 157);
	set("material", "stone");
	set("wear_msg", "[33m$N[33m×°±¸[1;37m¿×È¸ÓğÒÂ[2;37;0m[33m¡£[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁË[1;37m¿×È¸ÓğÒÂ[2;37;0m[33m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
