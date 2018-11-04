// ITEM Made by player(·å·å:hjshzq) /data/item/h/hjshzq-pan.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jun 26 15:27:14 2002
#include <ansi.h>
#include <weapon.h>

inherit HAMMER;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36mÓÎÏ·¹âÅÌ[2;37;0m", ({ "pan" }));
	set_weight(11900);
	set("item_make", 1);
	set("unit", "°Ñ");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»°Ñ´¸¡£
[1;32mÕâÊÇÒ»ÕÅÊĞÃæÉÏ¿´²»µ½µÄÓÎÏ·¹âÅÌ£®ÅÌÃæÉÏ¾§Ó¨ÌŞÍ¸£¬ÏâÓĞÄÏ·Ç×êÊ¯£®¹âÅÌÖÜÎ§ÓĞ·æÀûµÄ¾â³İ£¬ÉÏÃæÍ¿ÓĞÃğº¦Áé£®Ê¹ÈË¼ûÁË²»º®¶øÀõ£®[2;37;0m
´¸±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º·å·å(hjshzq)
");
	set("value", 2000000);
	set("point", 135);
	set("material", "stone");
	set("wield_msg", "[35mÖ»Ìı¡°ßÑµ±¡±Ò»Éù£¬$NÊÖÖĞÒÑ¶à³öÒ»Îï£¬Ö»¼û$NÄ¿ÖĞ¾«¹âËÄÉä£¬Íş·çÁİÁİ£¬ÍğÈôÌìÉñ£®ÊÖÖĞÖ®Îï£¬ÎËÎËÖ®Éù´ó×÷£®ÖÚÈËÖ»¾õµÃÆøÑªÉÏÓ¿£¬Ñ¹ÒÖÄÑµ±£¬·×·××øÏÂÔË¹¦µ÷Ï¢£®[2;37;0m\n");
	set("unwield_msg", "[1;32mÖ»Ìı¡°ïÏïÏ¡±Ò»Éù£¬$NÒ»ÉùÉÏÌ¾£¬½«ÓÎÏ·¹âÅÌÊÕ»ØÑü¼ä£¬ÎËÎË¼¸ÉùÈÔÊÇÓàÏì²»¾ø£®[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_hammer(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
