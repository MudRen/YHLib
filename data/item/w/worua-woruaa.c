// ITEM Made by player(Ê®¶Î:worua) /data/item/w/worua-woruaa.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Aug 23 22:16:48 2002
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m°Ù¶ÎÑ¥[2;37;0m", ({ "woruaa" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "Ë«");
	set("long", "ÕâÊÇÓÉ[37m¾«Ìú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ë«Ñ¥×Ó¡£
ÕâÊÇÓÉÌì²ÅÊ®¶ÎÖÆ×÷µÄ×îĞÂÆ·ÅÆÔË¶¯Ğ¬¼Û¸ñ²»·ÆÊµÓÃ²»¸ß[2;37;0m
Ñ¥×ÓÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÊ®¶Î(worua)
");
	set("value", 800000);
	set("point", 12);
	set("material", "iron");
	set("wear_msg", "ÎŞ[2;37;0m\n");
	set("remove_msg", "[1;37mµĞ[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
