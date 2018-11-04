// ITEM Made by player(ÎÚÀÏ¶ş:wulaoer) /data/item/w/wulaoer-boots.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jul 15 20:45:42 2002
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33mÀ××ß[2;37;0m", ({ "boots" }));
	set_weight(720);
	set("item_make", 1);
	set("unit", "Ë«");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ë«Ñ¥×Ó¡£
[1;37mÓÉ[2;37;0m¡¸[1;33mÀ××ß[2;37;0m¡¹[1;37m»Ã»¯¶ø³ÉµÄÒ»Ë«Õ½Ñ¥£¬ÖÜÉíÒşÔ¼É¢·¢×Åµ­µ­µÄ¹âÃ¢¡£[2;37;0m
Ñ¥×ÓÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÎÚÀÏ¶ş(wulaoer)
");
	set("value", 2000000);
	set("point", 100);
	set("material", "stone");
	set("wear_msg", "[1;37m$N´Ó±³ºó³é³öµÚÁù°Ñ½££¬°µºÈÒ»Éù[2;37;0m¡¸[1;33mµØ[2;37;0m¡¹[1;37m£¬½£ÉíÁ¢¿Ì¹â»¯³ÉÒ»Ë«Õ½Ñ¥¡£[2;37;0m\n");
	set("remove_msg", "[1;33mµØÊÇÈáÈÍµÄÉúÃü¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
