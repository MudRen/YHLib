// ITEM Made by player(É½ÏÂÃÀ×Ó:xinxin) /data/item/x/xinxin-baby.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Oct 12 12:37:32 2002
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;35mÎŞ[1;36mµĞ[34mÕ½[32mÒÂ[2;37;0m", ({ "baby" }));
	set_weight(2400);
	set("item_make", 1);
	set("unit", "¼ş");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¼şÕ½ÒÂ¡£
Á¬ÑóÇ¹¶¼´ò²»Í¸µÄÎŞµĞÕ½ÒÂ£¬ÈÃÌìÏÂËùÓĞµÄÎŞ³ÜÖ®Í½¶¼ÍË±ÜÈıÉá¡£ÕâÊÇÕıÒåµÄÏóÕ÷£¬ÊÇËùÓĞÎäÁÖ¸ßÊÖÃÎÃÂÒÔÇóµÄ±¦±´¡£´ËÎïÖ»Ó¦ÌìÉÏÓĞ£¬ÈË¼äÄÜÓĞ¼¸»ØºÏ£¿[2;37;0m
Õ½ÒÂÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÉ½ÏÂÃÀ×Ó(xinxin)
");
	set("value", 2000000);
	set("point", 125);
	set("material", "stone");
	set("wear_msg", "[33m$N[33m×°±¸[1;35mÎŞ[1;36mµĞ[34mÕ½[32mÒÂ[2;37;0m[33m¡£[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁË[1;35mÎŞ[1;36mµĞ[34mÕ½[32mÒÂ[2;37;0m[33m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
