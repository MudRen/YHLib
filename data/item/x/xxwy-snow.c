// ITEM Made by player(ÎŞÃû:xxwy) /data/item/x/xxwy-snow.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue May 21 14:11:19 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36mÃ÷¼¡Ñ©[2;37;0m", ({ "snow" }));
	set_weight(1350);
	set("item_make", 1);
	set("unit", "Ë«");
	set("long", "ÕâÊÇÓÉ[1;32mÇ¬[1;37mÀ¤[1;33mÊ¯[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ë«ÌúÕÆ¡£
[1;36m½ÏÒ»°ãµÄÌúÕÆÎª¶Ì£¬è­è²ÓĞÈô°×Óñ£¬¹â»ª»ÔÓ³£¬áİ·ğÊÇ×îÃÀÀöµÄĞÂÑ©¡£[2;37;0m
ÌúÕÆÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÎŞÃû(xxwy)
");
	set("value", 2200000);
	set("point", 133);
	set("material", "stone");
	set("wear_msg", "$NÒ»Éù³¤Ğ¥£¬[1;36mÃ÷¼¡Ñ©[2;37;0mÓë$NÈÚÎªÒ»Ìå¡£[2;37;0m\n");
	set("remove_msg", "$N³¤Ì¾Ò»Éù£¬[1;36mÃ÷¼¡Ñ©[2;37;0m´Ó$NÊÖÉÏÍÑÁË¿ªÀ´¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/hand", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/strike", 10);
	set("armor_prop/armor", 10);

	setup();
}

string long() { return query("long") + item_long(); }
