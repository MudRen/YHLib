// ITEM Made by player(ÏãÀ¼:starflower) /data/item/s/starflower-star.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Mar 27 06:51:23 2003
#include <ansi.h>
#include <weapon.h>

inherit WHIP;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m±ÜÔÂĞß»¨[2;37;0m", ({ "star" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "¸ù");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¸ù±Ş¡£
[1;31mÇÉĞ¦½âÓ­ÈË£¬ÇçÑ©Ïã¿°Ï§¡£Ëæ·çµûÓ°·­£¬Îóµã³¯ÒÂ³à¡£[2;37;0m
±Ş±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÏãÀ¼(starflower)
");
	set("value", 2000000);
	set("point", 135);
	set("material", "stone");
	set("wield_msg", "[1;31m²½Ò¡½ğ´äÓñÉ¦Í·£¬Çã¹úÇã³ÇÊ¤Äª³î¡£Èô³ÑÏÉ×ËÓÎÂåÆÖ£¬¶¨ÖªÉñÅ®Ğ»·çÁ÷¡£[2;37;0m\n");
	set("unwield_msg", "[1;31mÇ§ÖêÌÒĞÓ²Î²î·¢£¬Ïë¼û»¨Ê±ÈËÈ´³î¡£ÔøãÃÂ½»úÇÙ¾Æ»á£¬´ºÍ¤Î©Ô¸Ò»ÑÍÁô¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_whip(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
