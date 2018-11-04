// ITEM Made by player(ÎÚÀÏ¶ş:wulaoer) /data/item/w/wulaoer-belt.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jul 15 20:44:02 2002
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32mÑı¸¿[2;37;0m", ({ "belt" }));
	set_weight(960);
	set("item_make", 1);
	set("unit", "Ìõ");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»ÌõÑü´ø¡£
[1;37mÓÉ[2;37;0m¡¸[1;32mÑı¸¿[2;37;0m¡¹[1;37m»Ã»¯¶ø³ÉµÄÒ»ÌõÑü´ø£¬ÖÜÉíÒşÔ¼É¢·¢×Åµ­µ­µÄ¹âÃ¢¡£[2;37;0m
Ñü´øÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÎÚÀÏ¶ş(wulaoer)
");
	set("value", 2000000);
	set("point", 100);
	set("material", "stone");
	set("wear_msg", "[1;37m$N´Ó±³ºó³é³öµÚÎå°Ñ½££¬°µºÈÒ»Éù[2;37;0m¡¸[1;32mº£[2;37;0m¡¹[1;37m£¬½£ÉíÁ¢¿Ì¹â»¯³ÉÒ»ÌõÑü´ø¡£[2;37;0m\n");
	set("remove_msg", "[1;32mº£ÊÇÍòÎïÖ®ÆğÔ´¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
