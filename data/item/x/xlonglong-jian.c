// ITEM Made by player(Ğ¡ÁúÁú:xlonglong) /data/item/x/xlonglong-jian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Oct 11 21:20:42 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37mÓÄÁéÉñ½£[2;37;0m", ({ "jian" }));
	set_weight(30000);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[2;37;0m[36mÌìÉ½ĞşÌú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºĞ¡ÁúÁú(xlonglong)
");
	set("value", 2200000);
	set("point", 151);
	set("material", "stone");
	set("wield_msg", "[1;36m$N[1;36mÒ»ÉùÇåĞ¥£¬¶¶³öÒ»±ú[1;36m$n[1;36m¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
