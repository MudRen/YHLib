// ITEM Made by player(ÎÚÀÏ¶ş:wulaoer) /data/item/w/wulaoer-jian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Jul 11 03:18:46 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31mºŞÌì[1;36mÊ®¶ş½£[2;37;0m", ({ "jian" }));
	set_weight(10000);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[2;37;0m[36mÌìÉ½ĞşÌú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[1;37m½£³¤Èı³ßÆß´ç£¬½£¼¹ÉÏËÆºõ¿ÌÓĞÃÜÃÜÂéÂéµÄĞ¡×Ö£¬ÄãÄıÉñÒ»¿´£¬È´Ê²Ã´Ò²¿´²»Çå¡£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÎÚÀÏ¶ş(wulaoer)
");
	set("value", 3000000);
	set("point", 370);
	set("material", "stone");
	set("wield_msg", "[1;37mÒ»ºŞÈË²ÅÎŞĞĞ£¬¶şºŞºìÑÕ±¡Ãü£¬ÈıºŞ½­ÀË²»Ï¢¡£\nËÄºŞÊÀÌ¬Ñ×Á¹£¬ÎåºŞÔÂÌ¨Ò×Â©£¬ÁùºŞÀ¼Ò¶¶à½¹¡£[2;37;0m\n");
	set("unwield_msg", "[1;37mÆßºŞºÓëàÉõ¶¾£¬°ËºŞ¼Ü»¨Éú´Ì£¬¾ÅºŞÏÄÒ¹ÓĞÎÃ¡£\nÊ®ºŞÑ¦ÂÜ²Øò³£¬Ê®Ò»ºŞÎ´³¢°Ü¹ı£¬Ê®¶şºŞÌìÏÂÎŞµĞ¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
