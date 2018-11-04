// ITEM Made by player(°²ÏôÈ»:jiao) /data/item/j/jiao-zhi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Mar 27 20:13:31 2003
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33mÃğÉñÕ¶[2;37;0m", ({ "zhi" }));
	set_weight(1190);
	set("item_make", 1);
	set("unit", "Ì×");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ì×Ö¸Ì×¡£
[1;31m°²ÏôÈ»Î¢Ò»ÄıÉñ£¬ÔËÆğ¾ÅÑôÉñ¹¦£¬½«ÕæÆøÄı¾ÛÔÚµ¤ÌïÖ®ÖĞ£¬ÑØÆæ¾­°ËÂö±é²¼È«Éí£¡[2;37;0m
Ö¸Ì×ÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º°²ÏôÈ»(jiao)
");
	set("value", 2000000);
	set("point", 171);
	set("material", "stone");
	set("wear_msg", "[1;31m$NÄ¬Äî¾ÅÑôÉñ¹¦µÄ¿Ú¾÷£ºËûÇ¿ÓÉËûÇ¿£¬Çå·ç·÷É½¸Ô¡£ËûºáÈÎËûºá£¬Ã÷ÔÂÕÕ´ó½­¡­¡­[2;37;0m\n");
	set("remove_msg", "[1;31mÉ²ÄÇ¼äÖ»¼ûÄãÈ«Éí¶ÙÊ±¸¡ÏÖ³öÒ»²ã¸ÕÃÍµÄ¾¢Æø£¬½«ÄãÈ«È«ÁıÕÖ¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/finger", 10);
	set("armor_prop/claw", 10);
	set("armor_prop/armor", 10);

	setup();
}

string long() { return query("long") + item_long(); }
