// ITEM Made by player(ÎÚÀÏ¶ş:wulaoer) /data/item/w/wulaoer-unarmed.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jul 15 20:47:40 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m±À½Ù[2;37;0m", ({ "unarmed" }));
	set_weight(1530);
	set("item_make", 1);
	set("unit", "Ë«");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ë«ÌúÕÆ¡£
[1;37mÓÉ[2;37;0m¡¸[1;31m±À½Ù[2;37;0m¡¹[1;37m»Ã»¯¶ø³ÉµÄÒ»¸±ÕÆÌ×£¬ÖÜÉíÒşÔ¼É¢·¢×Åµ­µ­µÄ¹âÃ¢¡£[2;37;0m
ÌúÕÆÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÎÚÀÏ¶ş(wulaoer)
");
	set("value", 2000000);
	set("point", 300);
	set("material", "stone");
	set("wear_msg", "[1;37m$N´Ó±³ºó³é³öµÚÆß°Ñ½££¬°µºÈÒ»Éù[2;37;0m¡¸[1;31m°µ[2;37;0m¡¹[1;37m£¬½£ÉíÁ¢¿Ì¹â»¯³ÉÒ»¸±ÕÆÌ×¡£[2;37;0m\n");
	set("remove_msg", "[1;31m°µÊÇ×îºóµÄ¾øÍû¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/hand", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/strike", 10);

	setup();
}

string long() { return query("long") + item_long(); }
