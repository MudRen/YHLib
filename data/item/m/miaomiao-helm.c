// ITEM Made by player(ÃçÁé:miaomiao) /data/item/m/miaomiao-helm.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Apr  7 17:02:48 2003
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m²ÊÁ«¿ø[2;37;0m", ({ "helm" }));
	set_weight(2550);
	set("item_make", 1);
	set("unit", "¶¥");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¶¥Í·¿ø¡£
[1;33m¶ä¶äÆß²ÊÁ«»¨¾Û³ÉµÄÍ·¿ø¡£[2;37;0m
Í·¿øÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÃçÁé(miaomiao)
");
	set("value", 2000000);
	set("point", 105);
	set("material", "stone");
	set("wear_msg", "[1;33mÖ»ÌıµÃ°ë¿ÕÖ®ÖĞÏÉÀÖÓ¯¿Õ£¬Åå»·Ö®Éù²»¾ø£¬Ï¼¹âÍòµÀ£¬¶ä¶äÆß²ÊÁ«»¨¾ÛÔÚ$NÍ·¶¥¡£[2;37;0m\n");
	set("remove_msg", "[1;33m$NÊÖÖ¸Çá»Ó½«¾Û¶¥Á«»¨»º»ºÊÕÈ¥¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
