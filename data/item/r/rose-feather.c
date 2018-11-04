// ITEM Made by player(ÓñÁáçç:rose) /data/item/r/rose-feather.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu May 23 04:47:07 2002
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m¿×È¸ÓğÒÂ[2;37;0m", ({ "feather" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "ÕÅ");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»ÕÅ»¤¼×¡£
[1;37mÕâÊÇÒ»¼ş³ö×ÔÌì¹¬Ö¯Å®ÃîÊÖÉñ²ÃµÄÓğÉ´ÇáÒÂ¡£¿îÊ½ĞÂÓ±±ğÖÂ£¬
[1;37mÇáÈáÆ®ÒİµÄ¡£·ÅÔÚÊÖÖĞ¼òÖ±ÇáÈôÎŞÎï£¬ÕæÊÇÒ»¼ş·şÊÎ¼«Æ·¡£[2;37;0m
»¤¼×ÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÓñÁáçç(rose)
");
	set("value", 2000000);
	set("point", 111);
	set("material", "stone");
	set("wear_msg", "[1;37m$NÇáÈáµÄÕ¹¿ªÒ»¼ş½à°×ÈçÑ©µÄÆ®ÒİÉ´ÒÂÇáÇáÅûÔÚÉíÉÏ£¬Ó³³ÄµÄ\n[1;37m$N¼¡·ôÈçÑ©Ò»°ã£¬Ò»ÕÅÓ¯Ó¯Ğ¦Á³Èç³öË®Ü½ÈØ£¬ÈÃÈËÒâ¶¯»êÒ¡¡£[2;37;0m\n");
	set("remove_msg", "[1;37m$NÇáÇáµÄ½«¿×È¸ÓğÒÂÍÑÁËÏÂÀ´¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
