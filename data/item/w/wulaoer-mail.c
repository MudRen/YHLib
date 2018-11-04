// ITEM Made by player(ÎÚÀÏ¶ş:wulaoer) /data/item/w/wulaoer-mail.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jul 15 20:42:15 2002
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36mîøÁÛ[2;37;0m", ({ "mail" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "ÕÅ");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»ÕÅ»¤¼×¡£
[1;37mÓÉ[2;37;0m¡¸[1;36mîøÁÛ[2;37;0m¡¹[1;37m»Ã»¯¶ø³ÉµÄÒ»Ì×»¤¼×£¬ÖÜÉíÒşÔ¼É¢·¢×Åµ­µ­µÄ¹âÃ¢¡£[2;37;0m
»¤¼×ÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÎÚÀÏ¶ş(wulaoer)
");
	set("value", 2000000);
	set("point", 200);
	set("material", "stone");
	set("wear_msg", "[1;37m$N´Ó±³ºó³é³öµÚËÄ°Ñ½££¬°µºÈÒ»Éù[2;37;0m¡¸[1;36m¿Õ[2;37;0m¡¹[1;37m£¬½£ÉíÁ¢¿Ì¹â»¯³ÉÒ»Ì×»¤¼×¡£[2;37;0m\n");
	set("remove_msg", "[1;36m¿ÕÊÇÁÉÀ«µÄĞØ½ó¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
