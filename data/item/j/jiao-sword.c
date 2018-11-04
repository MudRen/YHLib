// ITEM Made by player(°²ÏôÈ»:jiao) /data/item/j/jiao-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Sep 27 13:34:43 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33mÇá·ç½£[2;37;0m", ({ "sword" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º°²ÏôÈ»(jiao)
");
	set("value", 2000000);
	set("point", 144);
	set("material", "stone");
	set("wield_msg", "[1;36m$N[1;36mÒ»ÉùÇåĞ¥£¬¶¶³öÒ»±ú[1;36m$n[1;36m¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
