// ITEM Made by player(ÌúÓÎÏÄ:starhand) /data/item/s/starhand-zhanjia.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Mar 24 10:28:22 2003
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("»¤ÉíÕ½¼×[2;37;0m", ({ "zhanjia" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "ÕÅ");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»ÕÅ»¤¼×¡£
»¤¼×ÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÌúÓÎÏÄ(starhand)
");
	set("value", 2000000);
	set("point", 110);
	set("material", "stone");
	set("wear_msg", "[33m$N[33m×°±¸»¤ÉíÕ½¼×[2;37;0m[33m¡£[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁË»¤ÉíÕ½¼×[2;37;0m[33m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/parry", apply_armor() / 15 + 1);
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
