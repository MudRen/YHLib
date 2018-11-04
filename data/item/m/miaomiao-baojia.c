// ITEM Made by player(ÃçÁé:miaomiao) /data/item/m/miaomiao-baojia.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu May 09 02:29:48 2002
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36mÕæË¿[1;33m±¦¼×[2;37;0m", ({ "baojia" }));
	set_weight(2400);
	set("item_make", 1);
	set("unit", "¼ş");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¼şÕ½ÒÂ¡£
Ò»¼ûºÚ÷î÷îµÄ¼×£¬ºÁ²»ÆğÑÛ¡£[2;37;0m
Õ½ÒÂÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÃçÁé(miaomiao)
");
	set("value", 2000000);
	set("point", 186);
	set("material", "stone");
	set("wear_msg", "[1;33m$N´©ÉÏÒ»¼ş[1;36mÕæË¿[1;33m±¦¼×¡£[2;37;0m\n");
	set("remove_msg", "[1;33m$N½«[1;36mÕæË¿[1;33m±¦¼×ÍÑÁËÏÂÀ´¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
