// ITEM Made by player(ÄÉÀ¼:mong) /data/item/m/mong-ptz.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Nov 29 17:28:12 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36mÆÆÌìÕÆ[2;37;0m", ({ "ptz" }));
	set_weight(1350);
	set("item_make", 1);
	set("unit", "Ë«");
	set("long", "ÕâÊÇÓÉ[1;32mÇ¬[1;37mÀ¤[1;33mÊ¯[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ë«ÌúÕÆ¡£
[1;36mÕâÊÇÒ»¿é¾§Ó¨ÌŞÍ¸µÄÊ¯ÕÆ£¬Ê¯Ãæ¹â»ªÁ÷×ª£¬±ãËÆ»îÎïÒ»°ã¡£[2;37;0m
ÌúÕÆÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÄÉÀ¼(mong)
");
	set("value", 2200000);
	set("point", 194);
	set("material", "stone");
	set("wear_msg", "$NÃæÂ¶Äé»¨Ö®Òâ£¬¼ÀÆğ¾öÊ½£¬ö®Ê±±Ì²¨Á÷×ª£¬»ª¹âÍòÕÉ£¬Ëµ²»¾¡µÄÏéºÍ¡£\n[1;36mÆÆÌìÕÆ[2;37;0m³öÏÖÔÚ$NÊÖÖĞ¡£[2;37;0m\n");
	set("remove_msg", "[1;36mÆÆÌìÕÆ[2;37;0mÒ»ÉùÇáÏì£¬´Ó$NÕÆÉÏÏûÊ§²»¼û¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/strike", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/hand", 10);

	setup();
}

string long() { return query("long") + item_long(); }
