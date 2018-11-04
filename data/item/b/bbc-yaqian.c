// ITEM Made by player(¹ã²¥µçÌ¨:bbc) /data/item/b/bbc-yaqian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Mar 15 20:19:47 2003
#include <ansi.h>
#include <weapon.h>

inherit STAFF;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37mÑÀÇ©[2;37;0m", ({ "yaqian" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "¸ù");
	set("long", "ÕâÊÇÓÉ[2;37;0m[33mîÑ½ğÖñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¸ùÕÈ¡£
ÕÈ±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º¹ã²¥µçÌ¨(bbc)
");
	set("value", 1200000);
	set("point", 50);
	set("material", "stone");
	set("wield_msg", "ËÔ£¬²»ÖªµÀ´ÓÄÄÀï·É³öÀ´Ò»¸ùÑÀÇ©¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_staff(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
