// ITEM Made by player(Ğ¡´ô:xiaodai) /data/item/x/xiaodai-jian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Jul 11 03:08:29 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33mÍõµÀ[1;37m¾Å½£[2;37;0m", ({ "jian" }));
	set_weight(10000);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[2;37;0m[36mÌìÉ½ĞşÌú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºĞ¡´ô(xiaodai)
");
	set("value", 3200000);
	set("point", 500);
	set("material", "stone");
	set("wield_msg", "[1;33m$NàáµÄÒ»Éù´Ó±³ºó³é³öÍõµÀ[1;37m¾Å½££¬[1;33mµ«¼û½£ÉíÇàÃ¢ÒşÏÖ£¬Ò»¹ÉËàÉ±Ö®ÒâÓÍÈ»¶øÉú¡£[2;37;0m\n");
	set("unwield_msg", "[1;37m$N½«[1;33mÍõµÀ[1;37m¾Å½£»º»ºÊÕÈëÇÊÄÚ£¬Ë«ÊÖ»·ĞØ¶øÁ¢£¬ĞÄÖĞ¶Ù¸ĞºÀÆøÍòÇ§¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
