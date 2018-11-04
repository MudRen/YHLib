// ITEM Made by player(Ğ¡´ô:xiaodai) /data/item/x/xiaodai-armor.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jul 15 10:38:39 2002
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m¾µ»¨Ë®ÔÂ[2;37;0m", ({ "armor" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "ÕÅ");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»ÕÅ»¤¼×¡£
»¤¼×ÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºĞ¡´ô(xiaodai)
");
	set("value", 2000000);
	set("point", 150);
	set("material", "stone");
	set("wear_msg", "[33m$N[33m×°±¸[1;37m¾µ»¨Ë®ÔÂ[2;37;0m[33m¡£[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁË[1;37m¾µ»¨Ë®ÔÂ[2;37;0m[33m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
