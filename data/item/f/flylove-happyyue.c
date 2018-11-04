// ITEM Made by player(ÌìÓğ:flylove) /data/item/f/flylove-happyyue.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri May 24 13:41:04 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32mË®[1;36mÔÂ[2;37;0m", ({ "happyyue" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[1;32mÓĞÌìÓĞµØĞØ»³Ì¹µ´£¬ÓĞ²èÓĞ¾ÆÇéÅ¨ÒâÉî£¬·çÁ÷ÙÃÙÎË­×ğ³¤£¿ÎŞÓÇÎŞ³î¸è»¶Óï³©£¬ÎŞÄÕÎŞºŞĞ¦¿´²×É££¬ÔÆ¹ıÑÌÉ¢»¹ÓĞÎÒ£¡¡¡[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÌìÓğ(flylove)
");
	set("value", 2000000);
	set("point", 120);
	set("material", "stone");
	set("wield_msg", "[1;36m$N[1;36mÒ»ÉùÇåĞ¥£¬¶¶³öÒ»±ú[1;36m$n[1;36m¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
