// ITEM Made by player(ÔÂÓ°á°:gaowei) /data/item/g/gaowei-yuanzui.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Sep 25 03:33:45 2002
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[36mÔ­×ï[2;37;0m", ({ "yuanzui" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "ÕÅ");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»ÕÅ»¤¼×¡£
[33mÕâÊÇÉÏ¹ÅÉñÆ÷Ö®Ò»¡£²»ÖªµÀÊÇÊ²Ã´²ÄÁÏÖıÔìµÄÁ¬Éí¼×£¬±¦µ¶Àû½£¶¼²»ÄÜÉËÆä·ÖºÁ¡£[2;37;0m
»¤¼×ÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÔÂÓ°á°(gaowei)
");
	set("value", 2000000);
	set("point", 93);
	set("material", "stone");
	set("wear_msg", "$NÄîÆğÕÙ»½ÖäÓï£º\n[33m´óµØµÄ¾«ÁéÑ½£¬ÄãÕÆ¹Ü×Å×îÖÕµÄ·ÀÓùºÍ»Ö¸´¡£\n[33m°ÑÄãµÄÁ¦Á¿½è¸øÎÒ£¬ÄãÖÒÊµµÄĞÅÑöÕß¡£\n[1;34mÉ²ÄÇ¼ä¹â»ª´ó×÷£¬$NÉíÉÏ¶àÁËÒ»½£¹Å×¾µÄÁ¬Éí±£¼×¡£[2;37;0m\n");
	set("remove_msg", "[33m$NºöÈ»ÏİÈëµØÃæÖĞ£¬µ±ËûÔÙ´ÎÏİÉíµÄÊ±ºò£¬ÉíÉÏµÄÁ¬Éí»¤¼ÑÒÑ¾­ÏûÊ§²»¼ûÁË¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/parry", apply_armor() / 15 + 1);
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
