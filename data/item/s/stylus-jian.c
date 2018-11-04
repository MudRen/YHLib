// ITEM Made by player(ÃîÇß:stylus) /data/item/s/stylus-jian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Oct 12 19:41:06 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m¼²·çÄ§ÀÇ½£[2;37;0m", ({ "jian" }));
	set_weight(30000);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[2;37;0m[36mÌìÉ½ĞşÌú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[1;33mÕâÊÇÒ¹²æÍõºÚÄ¾¿­µÄÌùÉíÅå½£¡£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÃîÇß(stylus)
");
	set("value", 2200000);
	set("point", 126);
	set("material", "stone");
	set("wield_msg", "[1;31m$N[1;31mÒ»Éù³¤Ğ¥£¬ÊÖÖĞ»Ã³öÒ»°ÑÍ¨Éí÷îºÚµÄ³¤½£¡£\n[1;32mÌì¼ÊÖĞ³öÏÖÁÙ±ø¶·Õß½ÔÕóÁĞÔÚÇ°¼¸¸ö´ó×Ö¡£[2;37;0m\n");
	set("unwield_msg", "[1;33m$N±³¹ıÉíÈ¥Î¢Î¢Ò»Ğ¦£¬$n[1;33mÆ®É¢²»¼ûÁË¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
