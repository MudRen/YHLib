// ITEM Made by player(ÆÆÌì:potian) /data/item/p/potian-knife.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Aug  8 22:58:43 2002
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[36mÍÀµ¶[2;37;0m", ({ "knife" }));
	set_weight(30000);
	set("item_make", 1);
	set("unit", "°Ñ");
	set("long", "ÕâÊÇÓÉ[2;37;0m[36mÌìÉ½ĞşÌú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»°Ñµ¶¡£
ÕâÊÇÒ»°ÑÑªÁÜÁÜµÄ[36mÍÀµ¶[2;37;0m¡£[2;37;0m
µ¶±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÆÆÌì(potian)
");
	set("value", 2200000);
	set("point", 134);
	set("material", "stone");
	set("wield_msg", "$N¡¸à§¡¹µÄÒ»Éù³é³öÒ»±ú[36mÍÀµ¶[2;37;0mÎÕÔÚÊÖÖĞ¡£[2;37;0m\n");
	set("unwield_msg", "$N½«ÊÖÖĞµÄ[36mÍÀµ¶[2;37;0m²å»Øµ¶ÇÊ¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
