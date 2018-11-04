// ITEM Made by player(ÃçÁé:miaomiao) /data/item/m/miaomiao-laodao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jul 15 20:23:44 2002
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[36mßëß¶[2;37;0m", ({ "laodao" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "°Ñ");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»°Ñµ¶¡£
[30mÕâÊÇµ±ÄêÎäÁÖµÚÒ»ÆæÈË³óÃÃÃÃ±ÏÉúĞÄÑªÖ®×÷¡£ÎË¡¢ÎË£¬°¡Ñ½£¬ÓÖÀ´ÁË£¡[2;37;0m
µ¶±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÃçÁé(miaomiao)
");
	set("value", 2000000);
	set("point", 173);
	set("material", "stone");
	set("wield_msg", "[1;37mÖ»Ìı$N¿ÚÖĞÄîÄîÓĞ´Ê£¬ßë[36m$n[1;37mß¶£¬ÖÜÎ§µÄÈË¶ÙÊ±Í·Í´²»ÒÑ¡£[2;37;0m\n");
	set("unwield_msg", "$NÍ£Ö¹ÁË$n£¬ÖÜÎ§¶ÙÊ±°²¾²ÁËÏÂÀ´¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
