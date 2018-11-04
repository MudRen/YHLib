// ITEM Made by player(Ä§¶ÉÖÚÉú:iliilil) /data/item/i/iliilil-whip.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Oct 18 15:01:12 2002
#include <ansi.h>
#include <weapon.h>

inherit WHIP;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m´òÉñ±Ş[2;37;0m", ({ "whip" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "¸ù");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¸ù±Ş¡£
[1;31mÕâ¼şÉÏ¹ÅÉñ±ø¾ÍÊÇµ±Äê[1;35m½ª×ÓÑÀ·âÉñºóÊ§´«µÄ[1;33m´òÉñ±Ş¡£[2;37;0m
±Ş±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÄ§¶ÉÖÚÉú(iliilil)
");
	set("value", 2000000);
	set("point", 130);
	set("material", "stone");
	set("wield_msg", "[1;36m$N[1;36mÒ»ÉùÇåĞ¥£¬¶¶³öÒ»¸ù[1;36m$n[1;36m¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_whip(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
