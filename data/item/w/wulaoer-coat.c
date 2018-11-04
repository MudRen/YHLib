// ITEM Made by player(ÎÚÀÏ¶ş:wulaoer) /data/item/w/wulaoer-coat.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jul 15 18:46:37 2002
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37mÔÂÄ§[2;37;0m", ({ "coat" }));
	set_weight(2400);
	set("item_make", 1);
	set("unit", "¼ş");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¼şÕ½ÒÂ¡£
[1;37mÓÉ[2;37;0m¡¸[1;37mÔÂÄ§[2;37;0m¡¹[1;37m»Ã»¯¶ø³ÉµÄÒ»¼şÕ½ÒÂ£¬ÖÜÉíÒşÔ¼É¢·¢×Åµ­µ­µÄ¹âÃ¢¡£[2;37;0m
Õ½ÒÂÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÎÚÀÏ¶ş(wulaoer)
");
	set("value", 2000000);
	set("point", 250);
	set("material", "stone");
	set("wear_msg", "[1;37m$N´Ó±³ºó³é³öµÚ¶ş°Ñ½££¬°µºÈÒ»Éù[2;37;0m¡¸[1;37mÔÂ[2;37;0m¡¹[1;37m£¬½£ÉíÁ¢¿Ì¹â»¯³ÉÒ»¼şÕ½ÒÂ¡£[2;37;0m\n");
	set("remove_msg", "[1;37mÔÂÊÇÎŞ¾¡µÄÖÇ»Û¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
