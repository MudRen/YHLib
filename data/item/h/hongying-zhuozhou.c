// ITEM Made by player(ºìÓ§:hongying) /data/item/h/hongying-zhuozhou.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Dec 19 09:37:36 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m×çÖä[2;37;0m", ({ "zhuozhou" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[1;31mÕâ°Ñ½£³¤Èı³ß£¬½£ÉíÒşÏÖÒ»ÖÖ°µºìÉ«µÄ¹âÃ¢£¬´«ËµÖ»ÒªÓĞÈË°ÑÆäÆÆ½â£¬¾ÍÄÜ³ÉÎªºÅÁî¾ÅÌìÊ®µØ£¬Ê®ÍòÄ§ÉñÖ®Ö÷¡£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ººìÓ§(hongying)
");
	set("value", 2000000);
	set("point", 142);
	set("material", "stone");
	set("wield_msg", "[1;33mÒ»È­»÷Ïò´óµØ£¬É²Ê±¼ä¿ñ·ç´ó×÷£¬ÌìµØ¼äÒ»Æ¬»Ò°µ¡£Ò»°ÑÑªÉ«³¤½££¬ÂıÂı´Ó´óµØÁÑ¿ÚĞ±ÉıÉÏÀ´¡£[2;37;0m\n");
     set("unwield_msg", HIY"ÊÖÖĞ³¤½£ÔÚ¿ÕÆøÖĞÂıÂıµØÏûÊ§µÃÎŞÓ°ÎŞ×Ù¡£\n"NOR);
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
