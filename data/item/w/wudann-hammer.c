// ITEM Made by player(Ä½ÈİÏãÄİ:wudann) /data/item/w/wudann-hammer.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jul 22 08:35:58 2002
#include <ansi.h>
#include <weapon.h>

inherit HAMMER;
inherit F_ITEMMAKE;

void create()
{
	set_name("Ìú´¸[2;37;0m", ({ "hammer" }));
	set_weight(11900);
	set("item_make", 1);
	set("unit", "°Ñ");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»°Ñ´¸¡£
´¸±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÄ½ÈİÏãÄİ(wudann)
");
	set("value", 2000000);
	set("point", 127);
	set("material", "stone");
	set("wield_msg", "[1;36m$N[1;36mÒ»ÉùÇåĞ¥£¬¶¶³öÒ»°Ñ[1;36m$n[1;36m¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_hammer(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
