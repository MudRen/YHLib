// ITEM Made by player(Ğ¡¹Ï:abc) /data/item/a/abc-jiezhi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu May 09 22:02:12 2002
#include <ansi.h>
#include <weapon.h>

inherit XSWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("½á»é½äÖ¸[2;37;0m", ({ "jiezhi" }));
	set_weight(1350);
	set("item_make", 1);
	set("unit", "Ö§");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÀ×»ğº®¾§[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ö§óï¡£
ÕâÊÇĞ¡¹ÏËÍ¸øËï¾ıµÄ¶¨ÇéĞÅÎï¡£[2;37;0m
óï±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºĞ¡¹Ï(abc)
");
	set("value", 1600000);
	set("point", 97);
	set("material", "stone");
	set("wield_msg", "Ëï¾ı´÷ÉÏÁËÒ»Ã¶½á»é½äÖ¸¡£[2;37;0m\n");
	set("unwield_msg", "Ëï¾ıÍÑÏÂÁËÒ»Ã¶½á»é½äÖ¸¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_xsword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
