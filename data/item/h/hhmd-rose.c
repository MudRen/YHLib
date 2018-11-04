// ITEM Made by player(»¨ÂúµØ:hhmd) /data/item/h/hhmd-rose.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon May 27 21:39:21 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31mÃµ¹å[2;37;0m", ({ "rose" }));
	set_weight(1530);
	set("item_make", 1);
	set("unit", "Ë«");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ë«ÌúÕÆ¡£
[1;37mÕâÒ»°ÙÁã°Ë¶ä[1;31mÃµ¹å£¬[1;37m´ú±íÁË»¨ÂúµØÒ»¿Å[1;31m»ğÀ±À±[1;37mµÄĞÄ¡£[2;37;0m
ÌúÕÆÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º»¨ÂúµØ(hhmd)
");
	set("value", 2000000);
	set("point", 140);
	set("material", "stone");
	set("wear_msg", "[33m$N[33m×°±¸[1;31mÃµ¹å[2;37;0m[33m¡£[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁË[1;31mÃµ¹å[2;37;0m[33m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/strike", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/hand", 10);
	set("armor_prop/unarmed_damage", apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
