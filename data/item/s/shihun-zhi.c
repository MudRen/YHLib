// ITEM Made by player(Ê§»êÒı:shihun) /data/item/s/shihun-zhi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jul  3 20:08:06 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[37mÖ¸Ì×[2;37;0m", ({ "zhi" }));
	set_weight(1190);
	set("item_make", 1);
	set("unit", "Ì×");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ì×Ö¸Ì×¡£
[36mÒ»¸öºÁ²»ÆğÑÛµÄ[2;37;0m[37mÖ¸Ì×[2;37;0m[36m¡£[2;37;0m
Ö¸Ì×ÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÊ§»êÒı(shihun)
");
	set("value", 2000000);
	set("point", 138);
	set("material", "stone");
	set("wear_msg", "$n[36mà½àì×Å£º¡°¸ÃÎÒÁËÃ´£¿¡±[2;37;0m\n");
	set("remove_msg", "$n[36mÕæÊÇÉá²»µÃ×ßÑ½£¬¿ÉÊÇ£®£®£®ÎØÎØÎØÎØÎØÎØÎØÎØ[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/finger", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/claw", 10);
	set("armor_prop/unarmed_damage", apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
