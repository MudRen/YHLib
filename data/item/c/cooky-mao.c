// ITEM Made by player(Ìğ±ı:cooky) /data/item/c/cooky-mao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Feb 24 15:38:56 2003
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[37móãÎè[2;37;0m", ({ "mao" }));
	set_weight(30000);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[2;37;0m[36mÌìÉ½ĞşÌú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[37m¾ø´úÓĞ¼ÑÈË£¬ÓÄ¾ÓÔÚ¿Õ¹È¡£µ«¼ûĞÂÈËĞ¦£¬ÄÇÎÅ¾ÉÈË¿Ş¡£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÌğ±ı(cooky)
");
	set("value", 2200000);
	set("point", 188);
	set("material", "stone");
	set("wield_msg", "[37mÑàºè¹ıºóİº¹éÈ¥£¬Ï¸Ëã¸¡ÉúÇ§ÍòĞ÷¡£³¤ÓÚ´ºÃÎ¼¸¶àÊ±£¬É¢ËÆÇïÔÆÎŞÃÙ´¦¡£[2;37;0m\n");
	set("unwield_msg", "[37mÎÅÇÙ½âÅåÉñÏÉÂÂ£¬Íì¶ÏÂŞÒÂÁô²»×¡¡£È°¾ıÄª×÷¶ÀĞÑÈË£¬ÀÃ×í»¨¼äÓ¦ÓĞÊı¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
