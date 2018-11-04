// ITEM Made by player(Öî¸ğÏşÛ³:ccbzjcon) /data/item/c/ccbzjcon-bladea.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun May 05 12:11:17 2002
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[30mÄ§µ¶[2;37;0m", ({ "bladea" }));
	set_weight(6750);
	set("item_make", 1);
	set("unit", "°Ñ");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÀ×»ğº®¾§[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»°Ñµ¶¡£
µ¶±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÖî¸ğÏşÛ³(ccbzjcon)
");
	set("value", 1600000);
	set("point", 91);
	set("material", "stone");
	set("wield_msg", "$N³é³öÒ»°Ñ[1;33mÄ§Óò[30mÄ§µ¶[2;37;0mÎÕÔÚÊÖÖĞ¡£[2;37;0m\n");
	set("unwield_msg", "$N·ÅÏÂÊÖÖĞµÄ[1;33mÄ§Óò[30mÄ§µ¶[2;37;0m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
