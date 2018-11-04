// ITEM Made by player(ÔÂÓ°á°:gaowei) /data/item/g/gaowei-xue.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Sep  5 13:56:03 2002
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33mÌìÁéÑ¥[2;37;0m", ({ "xue" }));
	set_weight(720);
	set("item_make", 1);
	set("unit", "Ë«");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ë«Ñ¥×Ó¡£
[1;35mÕâÊÇÌìµØËÄ±¦Ö®Ò»£¬¼¯ÌìµØÁéÆøÖ®¾«»ªÔĞÓı¶ø³É¡£[2;37;0m
Ñ¥×ÓÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÔÂÓ°á°(gaowei)
");
	set("value", 2000000);
	set("point", 50);
	set("material", "stone");
	set("wear_msg", "[1;32m$NºöÈ»±»Ò»Õó¿ñ·ç¾íÆğ£¬µ±¿ñ·çÉ¢È¥µÄÊ±ºò£¬Ëû½ÅÉÏ¶àÁËÒ»¸ö¹Å×¾µÄ³¤Ñ¥[2;37;0m\n");
	set("remove_msg", "[1;36mÒ»Ê±¹âÃ¢´óÊ¢£¬ÁÁ¹âÉ¢È¥$N½ÅÏÂ³¤Ñ¥ÒÑ¾­ÏûÊ§²»¼ûÁË¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
