// ITEM Made by player(ÓñÁáçç:rose) /data/item/r/rose-lian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri May 03 01:04:46 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37mÇåÏã°×Á«[2;37;0m", ({ "lian" }));
	set_weight(1350);
	set("item_make", 1);
	set("unit", "Ë«");
	set("long", "ÕâÊÇÓÉ[1;32mÇ¬[1;37mÀ¤[1;33mÊ¯[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ë«ÌúÕÆ¡£
[1;37mÒ»¶äĞ¡Ğ¡µÄ°×É«µÄÁ«»¨£¬º¬°ú´ı·Å£¬É¢·¢³öµ­µ­µÄÇåÏã¡£[2;37;0m
ÌúÕÆÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÓñÁáçç(rose)
");
	set("value", 2200000);
	set("point", 147);
	set("material", "stone");
	set("wear_msg", "[37mĞŞÎå°ÙÄêÍ¬ÖÛ£¬ĞŞÇ§Äê¹²Õí¡£\n[1;36m$N[1;37mÁ½ÊÖ½»´í£¬ĞÎÈôÁ«»¨£¬¿ÚÖĞÄîµÀ£º¡°Ê¢¿ª°É£¬Á«»¨¡£¡±°×Á«²ÓÀÃµÄÕÀ·Å×Å£¬ÓÆÈ»ÔÚÇàÎíÖĞ¡£[2;37;0m\n");
	set("remove_msg", "[1;36m$N[1;37m°®Á¯µÄÌ¾Ï¢×Å£¬°ÑÊÖÉìÏòÁ«Åî¡£Ò»µÎÈçÑÛÀáµÄÁ«×ÓÂäÈë$NµÄÕÆÖĞ£¬ÁáççÌŞÍ¸£¬¹â»ªË¸È»£¬Äı³ÉÒ»Á£·ğÖé¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/hand", 10);
	set("armor_prop/strike", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
