// ITEM Made by player(°²ÓñÈË:yuren) /data/item/y/yuren-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Jul 18 10:36:54 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36mÇáÔÆ½£[2;37;0m", ({ "sword" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[1;35mÕâÊÇÒ»°ÑÓñ»Ê´óµÛÓÃ¹ıµÄ½££¬ÒÑÔÚÈË¼äÁ÷´«Ç§ÄêÖ®¾Ã¡£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º°²ÓñÈË(yuren)
");
	set("value", 2000000);
	set("point", 130);
	set("material", "stone");
	set("wield_msg", "[1;36m$N[1;36mÒ»ÉùÇåĞ¥£¬¶¶³öÒ»±ú[1;36m$n[1;36m¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
