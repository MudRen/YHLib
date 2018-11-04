// ITEM Made by player(¶ÎÁ¼:lhl) /data/item/l/lhl-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed May 29 21:41:45 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37mµÛÕßÉñ½£[2;37;0m", ({ "sword" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[1;33mÕâ±ú[1;37mµÛÕßÉñ½£[1;33mÍşÊ¤ĞùÔ¯È´ÏÔÎªÈËÖª£¬ÄË»ÆµÛÎªºóÊÀÕæÃüÌì×ÓËùÖı£¬
ÄÚÔÌÁúÂö£¬¾ßÓĞÄ³ÖÖÉñÆæµÄÁ¦Á¿¡£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º¶ÎÁ¼(lhl)
");
	set("value", 2000000);
	set("point", 119);
	set("material", "stone");
	set("wield_msg", "[1;37mµÛÕßÉñ½£[1;33m·ÉÁú°ã´ÜÈë$NÊÖÖĞ£¬ÁúÒ÷Ö®ÉùËæÖ®Ïì³¹ÌìµØ£¬ËÄÖÜ½ğ¹âÍòÕÉ¡£\nÖÚÈËÖ»¾õÊÖÖĞ±øÈĞÔÚ²»×¡µÄÉÏÏÂ°Ú¶¯£¬¾¹ËÆÔÚ¶ÔÕâ±ú[1;35mÉñ±ø[1;33mßµ°İĞĞÀñ¡£[2;37;0m\n");
	set("unwield_msg", "[1;34m$NÊÖ¸§½£Éí£¬¿ÚÖĞÇáÌ¾¡£[1;37mµÛÕßÉñ½£[1;34mÓÖ·ÉÁú°ãÌÚ¿Õ¶øÈ¥£¬ÁúÒ÷Ö®Éù½¥ÍË£¬ÖÚÈËÕâ²ÅËÉÁË¿ÚÆø¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
