// ITEM Made by player(³óÃÃÃÃ:chou) /data/item/c/chou-jian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat May 04 21:41:34 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[37mÃÃÃÃ½£[2;37;0m", ({ "jian" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[36mÕâÊÇ³óÃÃÃÃµÄËæÉí±¦Îï£¡[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º³óÃÃÃÃ(chou)
");
	set("value", 2000000);
	set("point", 133);
	set("material", "stone");
	set("wield_msg", "[36m$NÉìÊÖÒ»¶¶£¬½«$n[36m×°±¸ÔÚÊÖÉÏ¡£[2;37;0m\n");
	set("unwield_msg", "[36m$NËæÊÖÒ»»Ó£¬$n[36mÒÑÈëÇÊÄÚ¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
