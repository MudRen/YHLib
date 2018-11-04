// ITEM Made by player(ÔÂÓ°á°:gaowei) /data/item/g/gaowei-bian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Feb 20 21:05:51 2003
#include <ansi.h>
#include <weapon.h>

inherit WHIP;
inherit F_ITEMMAKE;

void create()
{
	set_name("Òò×Ó[2;37;0m", ({ "bian" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "¸ù");
	set("long", "ÕâÊÇÓÉ[37m²ø»êË¿[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¸ù±Ş¡£
±Ş±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÔÂÓ°á°(gaowei)
");
	set("value", 900000);
	set("point", 35);
	set("material", "silk");
	set("wield_msg", "[1;32m$NÊ©Õ¹ÉñÅ©±¾²İ¾­µãÏò´óÓí£¬´óÓí»ëÉíÍ¸³öÒ»Ë¿°×É«ÕôÆø¡£\n[1;33m´óÓíÍÂ³öÒ»¿ÚÂÌÑª£¬¿´À´ÓĞĞ©Ğ§¹û¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_whip(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
