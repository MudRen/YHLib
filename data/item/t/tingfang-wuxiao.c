// ITEM Made by player(ÎÚÍ¢·¼:tingfang) /data/item/t/tingfang-wuxiao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Jan  9 00:40:58 2003
#include <ansi.h>
#include <weapon.h>

inherit XSWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("ÎŞÏô[2;37;0m", ({ "wuxiao" }));
	set_weight(1350);
	set("item_make", 1);
	set("unit", "Ö§");
	set("long", "ÕâÊÇÓÉ[37m¾«Ìú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ö§óï¡£
óï±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÎÚÍ¢·¼(tingfang)
");
	set("value", 800000);
	set("point", 30);
	set("material", "iron");
	set("wield_msg", "[1;36m$N[1;36mÒ»ÉùÇåĞ¥£¬¶¶³öÒ»Ö§[1;36m$n[1;36m¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_xsword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
