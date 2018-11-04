// ITEM Made by player(°ô×Ó:dagou) /data/item/d/dagou-dagou.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Jun 25 17:52:25 2002
#include <ansi.h>
#include <weapon.h>

inherit STAFF;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m´ò[1;31m¹·[1;37m°ô[2;37;0m", ({ "dagou" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "¸ù");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¸ùÕÈ¡£
ÕÈ±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º°ô×Ó(dagou)
");
	set("value", 2000000);
	set("point", 180);
	set("material", "stone");
	set("wield_msg", "[1;36m$N[1;36mÒ»ÉùÇåĞ¥£¬¶¶³öÒ»¸ù[1;36m$n[1;36m¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_staff(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
