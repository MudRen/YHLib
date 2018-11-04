// ITEM Made by player(Ğ»Ïş·å:china) /data/item/c/china-pifeng.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Oct 13 13:57:23 2002
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;35mÄ§Ğ«Åû·ç[2;37;0m", ({ "pifeng" }));
	set_weight(2400);
	set("item_make", 1);
	set("unit", "¼ş");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¼şÕ½ÒÂ¡£
[1;35mÕâÊÇÒ»¼şË§´ôÁË¡¢¿á±ĞÁËµÄÅû·ç£¡Åû·çÉÏÓĞÒ»Ö»ÕÅÑÀÎè×¦µÄ¶¾Ğ«£¬¾İ´«ÌìĞ«×ùµÄÈË´©ÉÏËü»áÓĞÒâÏë²»µ½µÄĞ§¹û¡£[2;37;0m
Õ½ÒÂÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºĞ»Ïş·å(china)
");
	set("value", 2000000);
	set("point", 133);
	set("material", "stone");
	set("wear_msg", "[1;35mÔÚÕâÒ»Ë²¼ä£¬$N¾õµÃ×Ô¼º¼òÖ±¸úÉñÒ»Ñù¡£[2;37;0m\n");
	set("remove_msg", "[1;35m¿´×ÅÄ§Ğ«Åû·ç£¬Äã´¹ÏÑÈı³ß£¬ÊÖÒ²´À´ÀÓû¶¯¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
