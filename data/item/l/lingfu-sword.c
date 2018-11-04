// ITEM Made by player(Áé¸£:lingfu) /data/item/l/lingfu-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri May 17 14:03:43 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("³¤½£[2;37;0m", ({ "sword" }));
	set_weight(30000);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[2;37;0m[36mÌìÉ½ĞşÌú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÁé¸£(lingfu)
");
	set("value", 2200000);
	set("point", 136);
	set("material", "stone");
	set("wield_msg", "$N¡¸à§¡¹µÄÒ»Éù³é³öÒ»±ú³¤½£ÎÕÔÚÊÖÖĞ¡£[2;37;0m\n");
	set("unwield_msg", "$N½«ÊÖÖĞµÄ³¤½£²å»Ø½£ÇÊ¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
