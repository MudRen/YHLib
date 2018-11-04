// ITEM Made by player(ÉÛÁ÷Àá:liulei) /data/item/l/liulei-dao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Oct 21 17:08:39 2002
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m±ù»ğÈĞ[2;37;0m", ({ "dao" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "°Ñ");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»°Ñµ¶¡£
µ¶±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÉÛÁ÷Àá(liulei)
");
	set("value", 2000000);
	set("point", 135);
	set("material", "stone");
	set("wield_msg", "[1;36m$N[1;36mÒ»ÉùÇåĞ¥£¬¶¶³öÒ»°Ñ[1;36m$n[1;36m¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
