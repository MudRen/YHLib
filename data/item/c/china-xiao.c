// ITEM Made by player(Ğ»Ïş·å:china) /data/item/c/china-xiao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Oct 13 14:01:17 2002
#include <ansi.h>
#include <weapon.h>

inherit XSWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m³ÕĞÄÇé³¤óï[2;37;0m", ({ "xiao" }));
	set_weight(1020);
	set("item_make", 1);
	set("unit", "Ö§");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ö§óï¡£
[1;36mÕâÊÇÒ»Æ·¹ÅÉ«¹ÅÏãµÄÓñóï£¬¾İ´«ÈôÊÇ¡°ÌìÏÂµÚÒ»Çé³Õ¡±Ğ»Ïş·å´µÆğ³ÕĞÄÇé³¤óïÀ´£¬ÄĞÈËĞÄÔ³ÒâÂí£¬Å®ÈËÒâÂÒÇéÃÔ¡£
[2;37;0m
óï±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºĞ»Ïş·å(china)
");
	set("value", 2000000);
	set("point", 133);
	set("material", "stone");
	set("wield_msg", "[1;36m$NÊÖÖ´³ÕĞÄÇé³¤óï³¤Ò÷£º\nÒ»ÇĞ¶÷°®»á£¬ÎŞ³£ÄÑµÃ¾Ã\nÉúÊÀ¶àÎ·¾å£¬ÃüÎ£ì¶³¿Â¶\nÓÉ°®¹ÊÉúÓÇ£¬ÓÉ°®¹ÊÉú²À\nÈôÀëì¶°®Õß£¬ÎŞÓÇÒàÎŞ²À\n[2;37;0m\n");
	set("unwield_msg", "[1;36mÒ»ÇúÌı°Õ£¬Äã³¤Ì¾£º\nÎÊÊÀ¼äÇéÎªºÎÎï£¬Ö±½ÌÉúËÀÏàĞí£¿\n[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_xsword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
