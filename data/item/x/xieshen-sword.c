// ITEM Made by player(Ä½ÈİĞ°Éñ:xieshen) /data/item/x/xieshen-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Jan 21 08:45:15 2003
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37mÓÄ»ê½£[2;37;0m", ({ "sword" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÄ½ÈİĞ°Éñ(xieshen)
");
	set("value", 2000000);
	set("point", 144);
	set("material", "stone");
set("wield_msg", HIW "$NÄ¬ÔËÌ«Ğş¹¦£¬½«ÄÚÁ¦»ı¾ÛÓÚÖÜÉí¾­Âö£¬¶Ù¾õÈ«Éí»ëÈ»ÓĞÁ¦£¬¼á²»¿É´İ¡£\n" NOR);
            set("unwield_msg", HIG "$NÄ¬Ä¬ÔË¹¦£¬ÎôÈÕÏÀ¿ÍµºÊ¯±ÚÉÏµÄ¿Ú¾÷Ò»Ò»³ÊÏÖ£¬Ì«Ğş¹¦ÄÚ¾¢ÒÑ»¤ÓÚÈ«Éí¡£\n" NOR);
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
