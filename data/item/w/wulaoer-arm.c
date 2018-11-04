// ITEM Made by player(ÎÚÀÏ¶ş:wulaoer) /data/item/w/wulaoer-arm.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jul 15 18:48:53 2002
#include <ansi.h>
#include <armor.h>

inherit WRISTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34mÎŞÈĞ[2;37;0m", ({ "arm" }));
	set_weight(600);
	set("item_make", 1);
	set("unit", "¶Ô");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¶Ô»¤Íó¡£
[1;37mÓÉ[2;37;0m¡¸[1;34mÎŞÈĞ[2;37;0m¡¹[1;37m»Ã»¯¶ø³ÉµÄÒ»¶Ô»¤Íó£¬ÖÜÉíÒşÔ¼É¢·¢×Åµ­µ­µÄ¹âÃ¢¡£[2;37;0m
»¤ÍóÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÎÚÀÏ¶ş(wulaoer)
");
	set("value", 2000000);
	set("point", 80);
	set("material", "stone");
	set("wear_msg", "[1;37m$N´Ó±³ºó³é³öµÚÈı°Ñ½££¬°µºÈÒ»Éù[2;37;0m¡¸[1;34mĞÇ[2;37;0m¡¹[1;37m£¬½£ÉíÁ¢¿Ì¹â»¯³ÉÒ»¶Ô»¤Íó¡£[2;37;0m\n");
	set("remove_msg", "[1;34mĞÇÊÇÓÀºãµÄ×£¸£¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/hand", apply_armor() / 6 + 1);
	set("armor_prop/hammer", apply_armor() / 6 + 1);
	set("armor_prop/dagger", apply_armor() / 6 + 1);
	set("armor_prop/staff", apply_armor() / 6 + 1);
	set("armor_prop/strike", apply_armor() / 6 + 1);
	set("armor_prop/whip", apply_armor() / 6 + 1);
	set("armor_prop/cuff", apply_armor() / 6 + 1);
	set("armor_prop/stick", apply_armor() / 6 + 1);
	set("armor_prop/sword", apply_armor() / 6 + 1);
	set("armor_prop/unarmed", apply_armor() / 6 + 1);
	set("armor_prop/armor", apply_armor());
	set("armor_prop/blade", apply_armor() / 6 + 1);
	set("armor_prop/parry", apply_armor() / 6 + 1);
	set("armor_prop/club", apply_armor() / 6 + 1);
	set("armor_prop/claw", apply_armor() / 6 + 1);
	set("armor_prop/finger", apply_armor() / 6 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
