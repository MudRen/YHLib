// ITEM Made by player(Ìğ±ı:cooky) /data/item/c/cooky-breeze.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Oct  9 12:14:28 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32móãá°[2;37;0m", ({ "breeze" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[1;32m°µµ­Çá»ÆÌåĞÔÈá¡£ÇéÊè¼£Ô¶Ö»ÏãÁô¡£ºÎĞëÇ³±ÌÉîºìÉ«£¬×ÔÊÇ»¨ÖĞµÚÒ»Á÷¡£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÌğ±ı(cooky)
");
	set("value", 2000000);
	set("point", 144);
	set("material", "stone");
	set("wield_msg", "[1;32mÓÀÒ¹âûâû»¶ÒâÉÙ¡£¿ÕÃÎ³¤°²£¬ÈÏÈ¡³¤°²µÀ¡£Îª±¨½ñÄê´ºÉ«ºÃ¡£»¨¹âÔÂÓ°ÒËÏàÕÕ¡£[2;37;0m\n");
	set("unwield_msg", "[1;32mËæÒâ±­ÅÌËä²İ²İ¡£¾ÆÃÀÃ·Ëá£¬Ç¡³ÆÈË»³±§¡£×íÄª²å»¨»¨ÄªĞ¦¡£¿ÉÁ¯´ºËÆÈË½«ÀÏ¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
