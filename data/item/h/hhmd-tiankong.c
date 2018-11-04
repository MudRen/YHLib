// ITEM Made by player(»¨ÂúµØ:hhmd) /data/item/h/hhmd-tiankong.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Aug 15 18:39:43 2002
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36mÌì¿Õ[2;37;0m", ({ "tiankong" }));
	set_weight(2550);
	set("item_make", 1);
	set("unit", "¶¥");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¶¥Í·¿ø¡£
Í·¿øÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º»¨ÂúµØ(hhmd)
");
	set("value", 2000000);
	set("point", 84);
	set("material", "stone");
	set("wear_msg", "[33m$N[33m×°±¸[1;36mÌì¿Õ[2;37;0m[33m¡£[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁË[1;36mÌì¿Õ[2;37;0m[33m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
