// ITEM Made by player(Ìğ±ı:cooky) /data/item/c/cooky-lipper.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Jan 10 14:14:25 2003
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37móãÎè[2;37;0m", ({ "lipper" }));
	set_weight(1190);
	set("item_make", 1);
	set("unit", "Ì×");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ì×Ö¸Ì×¡£
[1;37m³õÎÅÕ÷ÑãÒÑÎŞ²õ£¬°Ù³ßÂ¥¸ßË®½ÓÌì¡£ÇàÅ®ËØ¶ğ¾ãÄÍÀä£¬ÔÂÖĞËªÀï¶·æ¿¾ê¡£[2;37;0m
Ö¸Ì×ÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÌğ±ı(cooky)
");
	set("value", 2000000);
	set("point", 157);
	set("material", "stone");
	set("wear_msg", "[1;37mìªìª¶«·çÏ¸ÓêÀ´£¬Ü½ÈØÌÁÍâÓĞÇáÀ×¡£½ğó¸ÄöËøÉÕÏãÈë£¬Óñ»¢Ç£Ë¿¼³¾®»Ø¡£[2;37;0m\n");
	set("remove_msg", "[1;37m¼ÖÊÏ¿úÁ±º«ŞòÉÙ£¬åµåúÁôÕíÎºÍõ²Å¡£´ºĞÄÄª¹²»¨Õù·¢£¬Ò»´çÏàË¼Ò»´ç»Ò¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/finger", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/claw", 10);
	set("armor_prop/armor", 10);

	setup();
}

string long() { return query("long") + item_long(); }
