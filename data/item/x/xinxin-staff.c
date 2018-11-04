// ITEM Made by player(É½ÏÂÃÀ×Ó:xinxin) /data/item/x/xinxin-staff.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Oct  4 12:08:04 2002
#include <ansi.h>
#include <weapon.h>

inherit STAFF;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[35m¶áÃü[1;36m·èÄ§ÕÈ[2;37;0m", ({ "staff" }));
	set_weight(12000);
	set("item_make", 1);
	set("unit", "¸ù");
	set("long", "ÕâÊÇÓÉ[2;37;0m[36mÕòÁúÊ¯[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¸ùÕÈ¡£
¿ï·öÕıÒå£¬×¨É±²»Òå£¬²»ÖÒ£¬²»Ğ¢Ö®ÄæÍ½[2;37;0m
ÕÈ±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÉ½ÏÂÃÀ×Ó(xinxin)
");
	set("value", 1400000);
	set("point", 83);
	set("material", "stone");
	set("wield_msg", "[1;36m$N[1;36mÒ»ÉùÇåĞ¥£¬¶¶³öÒ»¸ù[1;36m$n[1;36m¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_staff(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
