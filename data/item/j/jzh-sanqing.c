// ITEM Made by player(¾µÖĞ»¨:jzh) /data/item/j/jzh-sanqing.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Jun 22 19:01:03 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32mÈıÇå½£[2;37;0m", ({ "sanqing" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º¾µÖĞ»¨(jzh)
");
	set("value", 2000000);
	set("point", 135);
	set("material", "stone");
	set("wield_msg", "[1;34mÖ»¼ûÒ»ÉùÇáĞ¥£¬´Ó±³ºó³é³öÒ»°ÑÁ÷¹âËÄÉäµÄÀû½££¬Ë²¼äºÆÈ»ÕıÆø²¼ÂúÄãÈ«Éí[2;37;0m\n");
	set("unwield_msg", "[37m»¹½£ÈëÇÊ£¬ºÆÈ»ÕıÆøÂıÂıÏûÍË[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
