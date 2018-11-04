// ITEM Made by player(ÓãÈÎ°¿:ainian) /data/item/a/ainian-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Aug 16 19:17:07 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[32m³¤½£[2;37;0m", ({ "sword" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[32mÕâÊÇÒ»±úÆÕÍ¨µÄ¾«¸Ö½££¬Ò»°ãµÄ½£¿Í¶¼Åä´ø´Ë½£¡£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÓãÈÎ°¿(ainian)
");
	set("value", 2000000);
	set("point", 126);
	set("material", "stone");
	set("wield_msg", "[32m$N¡¸à§¡¹µÄÒ»Éù³é³öÒ»±ú³¤½£ÎÕÔÚÊÖÖĞ¡£[2;37;0m\n");
	set("unwield_msg", "[32m$N½«ÊÖÖĞµÄ³¤½£²å»Ø½£ÇÊ¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
