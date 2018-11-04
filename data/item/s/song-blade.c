// ITEM Made by player(ËÎÔ¶ÇÅ:song) /data/item/s/song-blade.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Sep  3 13:59:28 2002
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("¸Öµ¶[2;37;0m", ({ "blade" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "°Ñ");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»°Ñµ¶¡£
ÕâÊÇÒ»±úÁÁ»Î»ÎµÄ¸Öµ¶£¬ÆÕÍ¨¹Ù±øµÄ³£±¸ÎäÆ÷¡£[2;37;0m
µ¶±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºËÎÔ¶ÇÅ(song)
");
	set("value", 2000000);
	set("point", 141);
	set("material", "stone");
	set("wield_msg", "$N¡¸à§¡¹µÄÒ»Éù³é³öÒ»±ú¸Öµ¶ÎÕÔÚÊÖÖĞ¡£[2;37;0m\n");
	set("unwield_msg", "$N½«ÊÖÖĞµÄ¸Öµ¶²å»Øµ¶ÇÊ¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
