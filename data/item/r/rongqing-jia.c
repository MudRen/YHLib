// ITEM Made by player(ÄÉÀ¼ÈİÇé:rongqing) /data/item/r/rongqing-jia.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Sep 18 20:46:35 2002
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[37mÈíâ¬¼×[2;37;0m", ({ "jia" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "ÕÅ");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»ÕÅ»¤¼×¡£
[37mÏà´«ÎªÎôÈÕ»ÆÒ©Ê¦»¤ÉíÈí¼×£¬µ¶Ç¹²»Èë£¬°Ù¶¾²»ÇÖ¡£[2;37;0m
»¤¼×ÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÄÉÀ¼ÈİÇé(rongqing)
");
	set("value", 2000000);
	set("point", 111);
	set("material", "stone");
	set("wear_msg", "[33m$N[33m×°±¸[2;37;0m[37mÈíâ¬¼×[2;37;0m[33m¡£[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁË[2;37;0m[37mÈíâ¬¼×[2;37;0m[33m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/parry", apply_armor() / 15 + 1);
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
