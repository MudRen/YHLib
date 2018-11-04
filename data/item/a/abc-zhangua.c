// ITEM Made by player(Ğ¡¹Ï:abc) /data/item/a/abc-zhangua.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue May 07 10:36:09 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[36mÕ¶¹Ï½£[2;37;0m", ({ "zhangua" }));
	set_weight(30000);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[2;37;0m[36mÌìÉ½ĞşÌú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
´Ë½£ÓÌÈç²Ëµ¶£¬¿´À´Ö»ÄÜÓÃÀ´Õ¶¹Ï¡£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºĞ¡¹Ï(abc)
");
	set("value", 2200000);
	set("point", 400);
	set("material", "stone");
	set("wield_msg", "[1;36m$N[1;36mÒ»ÉùÇåĞ¥£¬¶¶³öÒ»±ú[1;36m$n[1;36m¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
