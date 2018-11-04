// ITEM Made by player(ÃçÒİ:kong) /data/item/k/kong-jingtian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Jul  2 00:05:29 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m¾ªÌìÖ¸[2;37;0m", ({ "jingtian" }));
	set_weight(3500);
	set("item_make", 1);
	set("unit", "Ì×");
	set("long", "ÕâÊÇÓÉ[1;37må¾ÓîÌì¾§[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ì×Ö¸Ì×¡£
[1;36mÒ»¿é´¿°×É«Ë®¾§Ö¸Ì×£¬¾§Ó¨ÌŞÍ¸£¬ÎŞÏ¾µÄ±íÃæÉä³öÒ«ÑÛµÄ¹âÔó¡£ÆäÖĞ·Â·ğÔÌ²Ø×ÅÇ§Ç§ÍòÍòµÄÉúÃü£¬ÉúÃüÁ÷¶¯²»Ï¢£¬É¢·¢³öÓîÖæµÄÁ¦Á¿¡£Õâ±ãÊÇ´«ËµÖĞµÄÖÁ±¦¡ª¡ª¾ªÌìÖ¸£¬Ïà´«Ö»ÓĞÔÚÌì¹¬ÖĞ²Å»á³öÏÖ¡£[2;37;0m
Ö¸Ì×ÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÃçÒİ(kong)
");
	set("value", 4200000);
	set("point", 474);
	set("material", "tian jing");
	set("wear_msg", "[1;36m$NÉìÖ¸Ò»µ¯¾ªÌìÖ¸£¬Ò»Éù¡°¶£¡±µÄÇáÏì¡£ÌìµØÎªÖ®Õğº³¡£[2;37;0m\n");
	set("remove_msg", "[1;36m$NÓÆÓÆÒ»Éù³¤Ì¾£¬ÇáÇáÊÃÈ¥¾ªÌìÖ¸ÉÏµÄÑª¼££¬ËæÊÖÌ×ÔÚÊÖÉÏ¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/finger", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/claw", 10);

	setup();
}

string long() { return query("long") + item_long(); }
