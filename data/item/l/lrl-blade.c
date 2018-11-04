// ITEM Made by player(ºúÓ³Ñ©:lrl) /data/item/l/lrl-blade.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Apr 26 21:05:43 2002
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36mÀäÔÂ±¦µ¶[2;37;0m", ({ "blade" }));
	set_weight(30000);
	set("item_make", 1);
	set("unit", "°Ñ");
	set("long", "ÕâÊÇÓÉ[2;37;0m[36mÌìÉ½ĞşÌú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»°Ñµ¶¡£
[1;36mÕâÊÇÒ»±úĞÎÈçÀäÔÂµÄ±¦µ¶£¬Õû¸öµ¶ÉíÀäÆøÉ­É­£¬ÈñÀûÎŞ±È¡£[2;37;0m
µ¶±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ººúÓ³Ñ©(lrl)
");
	set("value", 2200000);
	set("point", 120);
	set("material", "stone");
	set("wield_msg", "[1;36m$N³é³ö±úĞÎÈçÀäÔÂµÄ³¤µ¶£¬¶ÙÊ±Ö»¾õº®Æø±ÆÈË£¬µ¶¹âÈçË®£¬Á÷×ª²»¶¨¡£[2;37;0m\n");
	set("unwield_msg", "[1;36m$Nµ¯µ¶ÇåĞ¥£¬ĞÄÖĞ¸Ğ¿®£¬½«ÀäÔÂ±¦µ¶²å»Øµ¶ÇÊ¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
