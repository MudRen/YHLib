// ITEM Made by player(ÓãÈÎ°¿:ainian) /data/item/a/ainian-sworda.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Mar 22 11:23:16 2003
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("³¤½£[2;37;0m", ({ "sworda" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;35mÉñÌú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
ÕâÊÇÒ»±úÆÕÍ¨µÄ¾«¸Ö½££¬Ò»°ãµÄ½£¿Í¶¼Åä´ø´Ë½£¡£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÓãÈÎ°¿(ainian)
");
	set("value", 2200000);
	set("point", 195);
	set("material", "magic stone");
	set("wield_msg", "$N¡¸à§¡¹µÄÒ»Éù³é³öÒ»±ú³¤½£ÎÕÔÚÊÖÖĞ¡£[2;37;0m\n");
	set("unwield_msg", "$N½«ÊÖÖĞµÄ³¤½£²å»Ø½£ÇÊ¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
