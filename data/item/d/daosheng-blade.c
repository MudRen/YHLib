// ITEM Made by player(ºú³Õ:daosheng) /data/item/d/daosheng-blade.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Jun 04 19:33:30 2002
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37mÈáÇé[2;37;0m", ({ "blade" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "°Ñ");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»°Ñµ¶¡£
ÕâÊÇÀ´×ÔĞùÔ¯Å®ÉñµÄ[1;37mÈáÇé[2;37;0m
µ¶±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ººú³Õ(daosheng)
");
	set("value", 2000000);
	set("point", 126);
	set("material", "stone");
	set("wield_msg", "[1;33mÍ»È»ÇéÈËµÄÃû×ÖÔÚÄÔº£ÖĞ¸¡ÏÖÒ»¹É³å¶¯»¯ÎªÇ¿ÁÒµÄ°ÔÆøÎ§ÈÆÔÚÖÜÎ§ºö¶øÓÖ»¯Îª[1;37mÈáÇé[2;37;0m\n");
	set("unwield_msg", "[1;31mË¿Ë¿ÃÛÒâÈç³±Ë®°ãÏòÄãÓ¿À´£¬ºÃËÆÇéÈËÎÂÈáµÄ°®¸§£¬[1;37mÈáÇé[1;31mËÆË®[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
