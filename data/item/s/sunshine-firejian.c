// ITEM Made by player(ÁÒÑôÖ®ÖË:sunshine) /data/item/s/sunshine-firejian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Jul 11 04:29:47 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m»ğ[1;37mÖ®[1;36mÈĞ[2;37;0m", ({ "firejian" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[1;37m½£³¤Èı³ß¶ş´ç£¬ÖØÁùÊ®ËÄ½ï£¬Õû¸ö½£Éí²»¶ÏµØÏòËÄÖÜÉ¢·¢×Å×ÆÈÈµÄ[1;31m»ğÆø[1;37m¡£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÁÒÑôÖ®ÖË(sunshine)
");
	set("value", 2200000);
	set("point", 387);
	set("material", "stone");
	set("wield_msg", "[1;37m$Nµ¥ÊÖ°´ÔÚ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[1;37mÉÏ£¬ÄÚ¾¢Ò»·Å£¬Ö»¼ûÒ»ÍÅÎíÆø¹ıºó£¬$NÊÖÖĞÍ»È»ÏÖ³öÒ»°Ñ[1;31m»ğºì[1;37mµÄÀûÈĞ¡£[2;37;0m\n");
	set("unwield_msg", "[1;37m$Nµ¥ÊÖ³Ö½£ËæÊÖ±È»­×Å£¬½£Éí½¥½¥±»ÍÅÍÅÊªÆøËù¸²¸Ç£¬Ò»Õó·ç´µ¹ı£¬$n[1;37m¾¹È»Æ¾¿ÕÏûÊ§µØÎŞÓ°ÎŞ×ÙÁË¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
