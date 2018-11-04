// ITEM Made by player(·çÔÆ:fengyun) /data/item/f/fengyun-long.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun May 19 19:20:18 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m÷¼÷Ã½£[2;37;0m", ({ "long" }));
	set_weight(12000);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[2;37;0m[36mÕòÁúÊ¯[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º·çÔÆ(fengyun)
");
	set("value", 1400000);
	set("point", 79);
	set("material", "stone");
	set("wield_msg", "[1;31m¡°ÄÃÇ®ÁË¡­¡­¡±[1;37m¿ÕÖĞ´«À´Ò»ÕóÅ­ºğ¡£ÄãÏÅµÄ»ê·ÉÆÇÉ¢£¬Á¬Ã¦ÄÃ³öÉíÉÏµÄÇ®¹§¾´µÄµİ¸ø$N¡£[2;37;0m\n");
	set("unwield_msg", "[1;37m¡°¹ö¡­¡­²ÅÕâÃ´Ò»µã£¬ËãÀûÏ¢ºÃÁË¡±¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
