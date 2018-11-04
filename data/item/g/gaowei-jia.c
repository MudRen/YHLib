// ITEM Made by player(ÔÂÓ°á°:gaowei) /data/item/g/gaowei-jia.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Sep  5 14:03:04 2002
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m»Ã¼×[2;37;0m", ({ "jia" }));
	set_weight(2400);
	set("item_make", 1);
	set("unit", "¼ş");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¼şÕ½ÒÂ¡£
[35mÕâÊÇÌìµØËÄ±¦Ö®Ò»£¬¼¯ÌìµØÁéÆøÖ®¾«»ªÔĞÓı¶ø³É¡£[2;37;0m
Õ½ÒÂÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÔÂÓ°á°(gaowei)
");
	set("value", 2000000);
	set("point", 126);
	set("material", "stone");
	set("wear_msg", "[1;33m$NºöÈ»±»Ò»Õó¿ñ·ç¾íÆğ£¬µ±¿ñ·çÉ¢È¥µÄÊ±ºò£¬ËûÉíÉÏ¶àÁËÒ»¸öÈçÃÎËÆ»ÃµÄ³¤ÉÀ¡£[2;37;0m\n");
	set("remove_msg", "[37mÒ»Ê±¹âÃ¢´óÊ¢£¬ÁÁ¹âÉ¢È¥$NÉíÉÏµÄ³¤ÉÀÒÑ¾­ÏûÊ§²»¼ûÁË¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
