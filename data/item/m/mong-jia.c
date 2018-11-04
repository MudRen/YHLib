// ITEM Made by player(ÄÉÀ¼:mong) /data/item/m/mong-jia.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Sep  5 09:19:32 2002
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36mÈí¼×[2;37;0m", ({ "jia" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "ÕÅ");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»ÕÅ»¤¼×¡£
ÕâÊÇÒ»¼şÌìÇàÉ«»¤¼×£¬ÈáÈíµÄ±íÃæÉä³öÒ«ÑÛµÄ¹âÔó¡£ÕâÊÇ´«ËµÖĞµÄÖÁ±¦£º[1;36mÈí¼×[2;37;0m¡£[2;37;0m
»¤¼×ÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÄÉÀ¼(mong)
");
	set("value", 2000000);
	set("point", 131);
	set("material", "stone");
	set("wear_msg", "$NÎûÎûÒ»Ğ¦£¬´©ÉÏ[1;36mÈí¼×[2;37;0m¡£[2;37;0m\n");
	set("remove_msg", "$NÎûÎûÒ»Ğ¦£¬ÍÑÏÂ[1;36mÈí¼×[2;37;0m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
