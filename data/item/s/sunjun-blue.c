// ITEM Made by player(Ëï¾ı:sunjun) /data/item/s/sunjun-blue.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Jun 15 19:01:45 2002
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[35mÌì²ÏÀ¼[2;37;0m", ({ "blue" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "ÕÅ");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»ÕÅ»¤¼×¡£
[1;32mÕâ[35mÌì²ÏÀ¼[1;32mÄËÊÇ²»Î·Ë®»ğ±øÈĞµÄÆæÎï£¬ÊÇÒ»Î»ÎäÁÖÇ°±²ÈıÊ®ÄêÇ°ÉîÈë¸ñÂ³É¯£¬²ÉµÃÈıÊ®ÁùÃ¶[35m¡°Ìì²ÏË¿¡±[1;32mÖ¯³ÉµÄÒ»¼ş±¦ÒÂ¡£[2;37;0m
»¤¼×ÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºËï¾ı(sunjun)
");
	set("value", 2000000);
	set("point", 103);
	set("material", "stone");
	set("wear_msg", "[1;36mÖ»¼û[1;32m$N[1;36mÉí´©µÄÀ¶ÒÂ£¬Í»È»Ïñ´µÆøËÆµÄ¹ÄÕÇ¿ªÀ´¡£ÈÕ¹âÕÕÉäÖ®ÏÂ£¬À¶É«ÖĞËÆºõ»¹´ø×Å[35m×Ï[1;36m¡¢[1;33m»Æ[1;36m¡¢[36mÇà[1;36m¡¢[1;37m°×[1;36m¡¢[31m³È[1;36m¡¢[33m¸Ì[1;36mµÄ¸÷ÖÖÑÕÉ«£¬ÉÁÒ«²»¶¨¡£[2;37;0m\n");
	set("remove_msg", "[1;31mÖ»¼û[1;37m$N[1;31mÓñóïÑï´¦£¬ÎèÆğÒ»Æ¬Òø¹â£¬ÍÑÏÂ[35mÌì²ÏÀ¼[1;31m£¬ÉíĞÎÍ»È»Áè¿Õ¶øÆğ£¬ÇáÆ®Æ®µÄÉÏÉıÈıÕÉÖ®¸ß£¬²ÊÒÂôæôæ£¬ĞäñÇÆ®¶¯£¬ÕıºÃÏóÒ»Ö»²Ê·ï¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
