// ITEM Made by player(Á¶Óü:lianyu) /data/item/l/lianyu-finger.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Aug 25 11:36:36 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37mÒ»Ö¸[1;31m¶Ï³¦[2;37;0m", ({ "finger" }));
	set_weight(1190);
	set("item_make", 1);
	set("unit", "Ì×");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ì×Ö¸Ì×¡£
[1;36mÇ§Äê¹ÅÓñÁ¶ÖÆ¶ø³ÉµÄ°âÖ¸£¬Ö¸ÉíÒ»°ëÆæ[1;31mÈÈ[1;36m£¬ÁíÒ»°ëÆæ[1;37mº®[1;36m£¬µ±ÕæÓĞ[1;31m´İ[1;32m¸Î[1;33m¶Ï[1;34m³¦[1;36mÖ®Íş¡£[2;37;0m
Ö¸Ì×ÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÁ¶Óü(lianyu)
");
	set("value", 2000000);
	set("point", 144);
	set("material", "stone");
	set("wear_msg", "[1;31mÊ®ÄêÉúËÀÁ½Ã£Ã£¡ª²»Ë¼Á¿¡ª×ÔÄÑÍü\n[1;32mÇ§Àï¹Â·Ø¡ªÎŞ´¦»°ÆàÁ¹\n[1;33m×İÊ¹Ïà·êÓ¦²»Ê¶¡ª³¾ÂúÃæ¡ª÷ŞÈçËª\n[2;37;0m\n");
	set("remove_msg", "[1;35mÒ¹À´ÓÄÃÎºö»¹Ïç¡ªĞ¡Ğù´°¡ªÕıÊá×±\n[1;36mÏà¶ÔÎŞÑÔ¡ªÎ©ÓĞÀáÇ§ĞĞ\n[1;37mÁÏµÃÄêÄê³¦¶Ï´¦¡ªÃ÷ÔÂÒ¹¡ª¶ÌËÉ¸Ú\n[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/finger", 10);
	set("armor_prop/claw", 10);

	setup();
}

string long() { return query("long") + item_long(); }
