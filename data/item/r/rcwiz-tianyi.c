// ITEM Made by player(ÍûÌìÑÄ:rcwiz) /data/item/r/rcwiz-tianyi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Aug 16 17:15:14 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31mÌìÒÂÎŞ·ì½£[2;37;0m", ({ "tianyi" }));
	set_weight(30000);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[2;37;0m[36mÌìÉ½ĞşÌú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÍûÌìÑÄ(rcwiz)
");
	set("value", 1);
	set("point", 280);
	set("material", "stone");
	set("wield_msg", "[1;36m$N[1;36mÒ»ÉùÇåĞ¥£¬¶¶³öÒ»±ú[1;36m$n[1;36m¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
