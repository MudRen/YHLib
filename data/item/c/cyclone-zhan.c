// ITEM Made by player(Ğı·ç:cyclone) /data/item/c/cyclone-zhan.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon May 27 13:32:38 2002
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34mĞı·çÕ¶[2;37;0m", ({ "zhan" }));
	set_weight(15000);
	set("item_make", 1);
	set("unit", "°Ñ");
	set("long", "ÕâÊÇÓÉ[1;37må¾ÓîÌì¾§[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»°Ñµ¶¡£
[1;34mÒ»°Ñ´«ËµÖĞÀ´×ÔÄ§½çµÄĞı·çÕ¶£¬ÉÏÃæ¸½ÂúÁËÀ´×ÔµØÓüÔ©»êµÄÈı»êÁùÆÇ¡£[2;37;0m
µ¶±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºĞı·ç(cyclone)
");
	set("value", 4200000);
	set("point", 505);
	set("material", "tian jing");
	set("wield_msg", "[1;34m¼ûÑÛÇ°Çà¹âÒ»ÉÁ£¬Æ¥Á·°ãµÄÒ»µÀÇà¹â£¬Ö±ÓÉ$n±³ºóÉÁµç°ãµØÆÆ¿Õ·ÉÆğÂäÈë$NÕÆÖĞ£¡[2;37;0m\n");
	set("unwield_msg", "[1;34m$n½«ÊÖÖĞµÄ$N²å»Ø±³ºó£¬Á³É«¸ü¼ÓÒõ³ÁÁË£¡[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
