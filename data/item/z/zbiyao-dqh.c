// ITEM Made by player(ÏªË®:zbiyao) /data/item/z/zbiyao-dqh.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Oct 23 13:32:39 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m¶à[34mÇé[35m»·[2;37;0m", ({ "dqh" }));
	set_weight(1190);
	set("item_make", 1);
	set("unit", "Ì×");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ì×Ö¸Ì×¡£
Ö¸Ì×ÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÏªË®(zbiyao)
");
	set("value", 2000000);
	set("point", 144);
	set("material", "stone");
	set("wear_msg", "[33m$N[33m×°±¸[1;31m¶à[34mÇé[35m»·[2;37;0m[33m¡£[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁË[1;31m¶à[34mÇé[35m»·[2;37;0m[33m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/finger", 10);
	set("armor_prop/claw", 10);
	set("armor_prop/armor", 10);

	setup();
}

string long() { return query("long") + item_long(); }
