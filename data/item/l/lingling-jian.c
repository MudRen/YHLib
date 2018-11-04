// ITEM Made by player(Ãç¶ù:lingling) /data/item/l/lingling-jian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue May 21 16:30:35 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32mÃç¶ù½£[2;37;0m", ({ "jian" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[1;32mÒ»ÖêĞ¡Ğ¡µÄÂÌÃç¶ù¡£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÃç¶ù(lingling)
");
	set("value", 2000000);
	set("point", 121);
	set("material", "stone");
	set("wield_msg", "ÅõÆğÒ»ÖêĞ¡Ğ¡µÄÂÌ$N¡£[2;37;0m\n");
	set("unwield_msg", "°ÑĞ¡Ğ¡µÄÂÌ$N·Å½ø»³Àï¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
