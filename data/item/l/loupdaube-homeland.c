// ITEM Made by player(Â³¶àÆÕ:loupdaube) /data/item/l/loupdaube-homeland.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Dec  2 09:09:57 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m¹ÊÏç[2;37;0m", ({ "homeland" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[1;33m»êÇ£ÃÎÈÆµÄµØ·½©¤©¤©¤¾ÍÊÇ¹ÊÏç£¡[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÂ³¶àÆÕ(loupdaube)
");
	set("value", 2000000);
	set("point", 139);
	set("material", "stone");
	set("wield_msg", "[1;36m$N[1;36mÒ»ÉùÇåĞ¥£¬¶¶³öÒ»±ú[1;36m$n[1;36m¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
