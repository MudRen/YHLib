// ITEM Made by player(Øßáõ:yanrong) /data/item/y/yanrong-clothb.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Jun 02 19:47:35 2002
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36måĞ[1;37mÒ£[1;32mÑ¥[2;37;0m", ({ "clothb" }));
	set_weight(720);
	set("item_make", 1);
	set("unit", "Ë«");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ë«Ñ¥×Ó¡£
Ñ¥×ÓÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºØßáõ(yanrong)
");
	set("value", 2000000);
	set("point", 54);
	set("material", "stone");
	set("wear_msg", "$N´©ÉÏÒ»Ë«[1;36måĞ[1;37mÒ£[1;32mÑ¥[2;37;0m¡£[2;37;0m\n");
	set("remove_msg", "$N½«[1;36måĞ[1;37mÒ£[1;32mÑ¥[2;37;0mÍÑÁËÏÂÀ´¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
