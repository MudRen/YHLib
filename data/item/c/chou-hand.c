// ITEM Made by player(³óÃÃÃÃ:chou) /data/item/c/chou-hand.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu May 30 10:04:15 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m·ÛÈ­[2;37;0m", ({ "hand" }));
	set_weight(1530);
	set("item_make", 1);
	set("unit", "Ë«");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ë«ÌúÕÆ¡£
[1;32mÕâÊÇ³óÃÃÃÃµÄ[1;37m·ÛÈ­[1;32m¡£[2;37;0m
ÌúÕÆÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º³óÃÃÃÃ(chou)
");
	set("value", 2000000);
	set("point", 151);
	set("material", "stone");
	set("wear_msg", "[1;32m$N´øÉÏ[1;37m·ÛÈ­[1;32m¿´À´ÊÇ×¼±¸×áÈËÁË¡£[2;37;0m\n");
	set("remove_msg", "[1;32m$N×áÍêÈËÁË°Ñ[1;37m·ÛÈ­[1;32mÊÕÁËÆğÀ´¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/strike", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/hand", 10);

	setup();
}

string long() { return query("long") + item_long(); }
