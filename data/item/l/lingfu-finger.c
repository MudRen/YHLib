// ITEM Made by player(Áé¸£:lingfu) /data/item/l/lingfu-finger.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Aug 22 22:04:27 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("Ö¸Ì×[2;37;0m", ({ "finger" }));
	set_weight(1190);
	set("item_make", 1);
	set("unit", "Ì×");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ì×Ö¸Ì×¡£
Ö¸Ì×ÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÁé¸£(lingfu)
");
	set("value", 2000000);
	set("point", 156);
	set("material", "stone");
	set("wear_msg", "$N´÷ÉÏÒ»¸±Ö¸Ì×¡£[2;37;0m\n");
	set("remove_msg", "$NĞ¶³ıÖ¸Ì×µÄ×°±¸¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/finger", 10);
	set("armor_prop/claw", 10);

	setup();
}

string long() { return query("long") + item_long(); }
