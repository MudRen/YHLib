// ITEM Made by player(´óµØ·ÉÓ¥:ddfy) /data/item/d/ddfy-staff.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Sep  7 17:02:22 2002
#include <ansi.h>
#include <weapon.h>

inherit STAFF;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m·è[1;33mÄ§[1;37mÕÈ[2;37;0m", ({ "staff" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "¸ù");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¸ùÕÈ¡£
ÕÈ±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º´óµØ·ÉÓ¥(ddfy)
");
	set("value", 2000000);
	set("point", 117);
	set("material", "stone");
	set("wield_msg", "[1;36m$N[1;36mÒ»ÉùÇåĞ¥£¬¶¶³öÒ»¸ù[1;36m$n[1;36m¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_staff(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
