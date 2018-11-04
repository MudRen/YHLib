// ITEM Made by player(×ÓÁê:lilac) /data/item/l/lilac-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Jun 11 12:41:35 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[34m³¾·â[35mËÄ¼¾[1;32mÀá[2;37;0m", ({ "sword" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[1;36mÎÒµÄ°®ÈË¡¡Ôøº¬Àá
[1;36m½«ÎÒÂñ²Ø
[1;36mÓÃÖéÓñ¡¡ÓÃÈéÏã
[1;36m½«ÎÒ¹â»¬µÄÉíÇû°ü¹ü
[1;36mÔÙÓÃ²ü¶¶µÄÊÖ¡¡½«ÄñÓğ
[1;36m²åÔÚÎÒÈç¶ĞµÄ·¢ÉÏ[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º×ÓÁê(lilac)
");
	set("value", 2000000);
	set("point", 121);
	set("material", "stone");
	set("wield_msg", "[35mÎÒÒÑÎŞÊ«\n[35mÊÀ¼äÒ²ÔÙÎŞ·É»¨¡¡ÎŞÏ¸Óê\n[35m³¾·âµÄËÄ¼¾°¡\n[35mÇë±ğ¿ŞÆü[2;37;0m\n");
	set("unwield_msg", "[34mÍò°ã¡¡Íò°ãµÄÎŞÄÎ\n[34m°®µÄÓà½ıÒÑÏ¨\n[34mÖØ»ØÈË¼ä\n[34mÃÍÈ»ĞÑ¾õÄÇÇ§ÌõÍòÌõ¡¡¶¼ÊÇ\n[34mÒÑÖªµÄÂ·¡¡ÒÑÁËÈ»µÄ¹ì¼£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
