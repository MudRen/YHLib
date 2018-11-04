// ITEM Made by player(ÃçÁé:miaomiao) /data/item/m/miaomiao-yaodai.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Apr  6 15:01:00 2003
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33mÏéÁú´ø[2;37;0m", ({ "yaodai" }));
	set_weight(960);
	set("item_make", 1);
	set("unit", "Ìõ");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»ÌõÑü´ø¡£
[1;33mÒ»ÌõÏéÁúÔÚÃçÁéÑü¼äÅÌÈÆ¡£[2;37;0m
Ñü´øÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÃçÁé(miaomiao)
");
	set("value", 2000000);
	set("point", 84);
	set("material", "stone");
	set("wear_msg", "[1;33mÌì¿ÕºöÏÖÓ§ÂçÇìÔÆ£¬Èğ¹âçÔÈÆ£¬ÔÆ¹âçÎç¿£¬ÔÆÖĞÒ»ÌõÏéÁú´ÓÌì¶ø½µÅÌÈÆÔÚ$NÑü¼ä¡£[2;37;0m\n");
	set("remove_msg", "[1;33mÑü¼äµÄÏéÁúÔÚ$NÉíÅÔÅÌÈÆÊıÖÜ³åÌì¶øÈ¥¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
