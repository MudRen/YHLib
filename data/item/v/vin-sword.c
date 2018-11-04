// ITEM Made by player(ĞùÔ¯ĞĞ:vin) /data/item/v/vin-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed May 29 19:10:42 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37mÖ½½£[2;37;0m", ({ "sword" }));
	set_weight(15);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;37mĞûÖ½[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[1;37mÕâÊÇÒ»ÕÅÓÉÆÕÍ¨Ö½ÕÅÕÛ³ÉµÄ½£¡£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºĞùÔ¯ĞĞ(vin)
");
	set("value", 1);
	set("point", 1000000);
	set("material", "stone");
	set("wield_msg", "[1;36m$N[1;36mÒ»ÉùÇåĞ¥£¬¶¶³öÒ»±ú[1;36m$n[1;36m¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
