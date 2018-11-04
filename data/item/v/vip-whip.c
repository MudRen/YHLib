// ITEM Made by player(×Ïôá:vip) /data/item/v/vip-whip.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Oct 19 17:39:33 2002
#include <ansi.h>
#include <weapon.h>

inherit WHIP;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32mÀë±ğ¹³[2;37;0m", ({ "whip" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "¸ù");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¸ù±Ş¡£
[1;33m½­ºşÉÏÖøÃûµÄ³¤±Ş£¬¾İËµËüµÄÇ°¶ËÓĞÒ»¸öĞ¡¹³£¬Ö»Òª±»¹³ÖĞµÄ¶«Î÷¶¼»áÀë±ğ£¬°üÀ¨ÈËµÄÉíÌå¡£[2;37;0m
±Ş±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º×Ïôá(vip)
");
	set("value", 2000000);
	set("point", 149);
	set("material", "stone");
	set("wield_msg", "[1;31m$NÄ¬Äî¾ÅÑôÉñ¹¦µÄ¿Ú¾÷£ºËûÇ¿ÓÉËûÇ¿£¬Çå·ç·÷É½¸Ô¡£ËûºáÈÎËûºá£¬Ã÷ÔÂÕÕ´ó½­¡­¡­\nÉ²ÄÇ¼äÖ»¼û$NÈ«Éí¶ÙÊ±¸¡ÏÖ³öÒ»²ã¸ÕÃÍµÄ¾¢Æø£¬½«$NÈ«È«ÁıÕÖ¡£\n$NÑÛÖĞ¾«¹âÉÁ¹ı£¬ÀäÀäµÄÉ¨¹ıËÄÖÜ£¬Ò»¹Éº®ÒâÁİÈ»¶øÆğ¡£[2;37;0m\n");
	set("unwield_msg", "[1;31m$NÎ¢Ò»ÄıÉñ£¬ÔËÆğ¾ÅÑôÉñ¹¦£¬½«ÕæÆøÄı¾ÛÔÚµ¤ÌïÖ®ÖĞ£¬ÑØÆæ¾­°ËÂö±é²¼È«Éí£¡[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_whip(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
