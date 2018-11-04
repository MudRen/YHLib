// ITEM Made by player(·å·å:hjshzq) /data/item/h/hjshzq-qiang.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Jun 18 19:04:26 2002
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m·À»ğÇ½[2;37;0m", ({ "qiang" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "ÕÅ");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»ÕÅ»¤¼×¡£
[1;31mÕâÊÇ·å·åµÄËæÉí»¤¼×£¬Õ¦Ò»¿´¾¹È»ÊÇ¶Â¸ßÇ½£¿£¿²»¿ÉË¼Òé£¡Ò²ĞíÇ½±Ú²ÅÊÇ×îºÃµÄ·À¾ß°É£¡£¡[2;37;0m
»¤¼×ÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º·å·å(hjshzq)
");
	set("value", 2000000);
	set("point", 105);
	set("material", "stone");
	set("wear_msg", "[1;31mÍ»È»Ö»¼û$NÔÚ×Ô¼ºÖÜÎ§ÀİÆğÁËÒ»¶Â¸ßÇ½£®¿´À´ÊÇ$NµÄ·À»¤Ö®Êõ°É£¡[2;37;0m\n");
	set("remove_msg", "[1;31m$N¿´¼ûÖÜÎ§Ò»ÇĞ¶¼°²È«ÁË£¬¾ÍÂíÉÏ°Ñ·À»ğÇ½³·ÁË£¡[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
