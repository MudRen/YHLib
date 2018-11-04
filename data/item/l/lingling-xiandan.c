// ITEM Made by player(Ãç¶ù:lingling) /data/item/l/lingling-xiandan.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Apr 10 09:42:31 2003
#include <ansi.h>
#include <armor.h>

inherit WRISTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("Éñ¶÷Í¨»ÛÏÉµ¤[2;37;0m", ({ "xiandan" }));
	set_weight(2250);
	set("item_make", 1);
	set("unit", "¶Ô");
	set("long", "ÕâÊÇÓÉ[37m¾«Ìú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¶Ô»¤Íó¡£
´«Ëµ´Ëµ¤ÄËÊÇÌì¹¬ÖĞµÄÉñÆ·£¬·²ÈË³ÔÁË¿ÉÒÔÆ½Ôö¸ù¹Ç¡£[2;37;0m
»¤ÍóÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÃç¶ù(lingling)
");
	set("value", 800000);
	set("point", 7);
	set("material", "iron");
	set("wear_msg", "[33m$N[33m×°±¸Éñ¶÷Í¨»ÛÏÉµ¤[2;37;0m[33m¡£[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁËÉñ¶÷Í¨»ÛÏÉµ¤[2;37;0m[33m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/blade", apply_armor() / 6 + 1);
	set("armor_prop/whip", apply_armor() / 6 + 1);
	set("armor_prop/club", apply_armor() / 6 + 1);
	set("armor_prop/dagger", apply_armor() / 6 + 1);
	set("armor_prop/cuff", apply_armor() / 6 + 1);
	set("armor_prop/unarmed", apply_armor() / 6 + 1);
	set("armor_prop/staff", apply_armor() / 6 + 1);
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 6 + 1);
	set("armor_prop/stick", apply_armor() / 6 + 1);
	set("armor_prop/claw", apply_armor() / 6 + 1);
	set("armor_prop/sword", apply_armor() / 6 + 1);
	set("armor_prop/hand", apply_armor() / 6 + 1);
	set("armor_prop/finger", apply_armor() / 6 + 1);
	set("armor_prop/strike", apply_armor() / 6 + 1);
	set("armor_prop/hammer", apply_armor() / 6 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
