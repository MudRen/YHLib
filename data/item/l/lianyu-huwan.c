// ITEM Made by player(Á¶Óü:lianyu) /data/item/l/lianyu-huwan.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Oct  9 11:59:58 2002
#include <ansi.h>
#include <armor.h>

inherit WRISTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36mÁùµÀ[1;37mÂÖ»Ø[2;37;0m", ({ "huwan" }));
	set_weight(600);
	set("item_make", 1);
	set("unit", "¶Ô");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¶Ô»¤Íó¡£
[1;31mÈË¼äµÀ[37m£¬[1;32mĞóÉúµÀ[37m£¬[1;33m¶ö¹íµÀ[37m£¬[1;34mĞŞÂŞµÀ[37m£¬[1;35mµØÓüµÀ[37m£¬[1;37mÌì¼«µÀ[2;37;0m
»¤ÍóÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÁ¶Óü(lianyu)
");
	set("value", 2000000);
	set("point", 37);
	set("material", "stone");
	set("wear_msg", "[33m$N[33m×°±¸[1;36mÁùµÀ[1;37mÂÖ»Ø[2;37;0m[33m¡£[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁË[1;36mÁùµÀ[1;37mÂÖ»Ø[2;37;0m[33m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/claw", apply_armor() / 6 + 1);
	set("armor_prop/hammer", apply_armor() / 6 + 1);
	set("armor_prop/dagger", apply_armor() / 6 + 1);
	set("armor_prop/staff", apply_armor() / 6 + 1);
	set("armor_prop/parry", apply_armor() / 6 + 1);
	set("armor_prop/blade", apply_armor() / 6 + 1);
	set("armor_prop/strike", apply_armor() / 6 + 1);
	set("armor_prop/stick", apply_armor() / 6 + 1);
	set("armor_prop/armor", apply_armor());
	set("armor_prop/club", apply_armor() / 6 + 1);
	set("armor_prop/finger", apply_armor() / 6 + 1);
	set("armor_prop/whip", apply_armor() / 6 + 1);
	set("armor_prop/hand", apply_armor() / 6 + 1);
	set("armor_prop/sword", apply_armor() / 6 + 1);
	set("armor_prop/unarmed", apply_armor() / 6 + 1);
	set("armor_prop/cuff", apply_armor() / 6 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
