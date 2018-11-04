// ITEM Made by player(ÔÂÓ°á°:gaowei) /data/item/g/gaowei-dai.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Sep 25 02:41:26 2002
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32mÈÄÔÂÌ«Ğé[2;37;0m", ({ "dai" }));
	set_weight(960);
	set("item_make", 1);
	set("unit", "Ìõ");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»ÌõÑü´ø¡£
[1;33mÕâÊÇÉÏ¹ÅÉñÆ÷Ö®Ò»£¬ÉÁË¸×ÅÕóÕó×Ï¹âµÄÑü´ø£¬²»ÖªÓÉºÎÎïËùÖ¯£¬¼áÈÍÓĞÈçĞşÌú¡£[2;37;0m
Ñü´øÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÔÂÓ°á°(gaowei)
");
	set("value", 2000000);
	set("point", 46);
	set("material", "stone");
	set("wear_msg", "[1;31m$NÎ¢Ò»ÄıÉñ£¬ÔËÆğ¾ÅÑôÉñ¹¦£¬½«ÕæÆøÄı¾ÛÔÚµ¤ÌïÖ®ÖĞ£¬ÑØÆæ¾­°ËÂö±é²¼È«Éí£¡\n[1;31m$NÄ¬Äî¾ÅÑôÉñ¹¦µÄ¿Ú¾÷£ºËûÇ¿ÓÉËûÇ¿£¬Çå·ç·÷É½¸Ô¡£ËûºáÈÎËûºá£¬Ã÷ÔÂÕÕ´ó½­¡­¡­\n[1;31mÉ²ÄÇ¼äÖ»¼û$NÈ«Éí¶ÙÊ±¸¡ÏÖ³öÒ»²ã¸ÕÃÍµÄ¾¢Æø¡£[2;37;0m\n");
	set("remove_msg", "[1;33mÒ»µÀ½ğ¹â»®¹ı£¬$NÑüÉÏµÄ³¤´ø£¬ÈÜÈë¿ÕÆøÏûÊ§²»¼û¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
