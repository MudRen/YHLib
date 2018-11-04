// ITEM Made by player(×ÓÁê:lilac) /data/item/l/lilac-zhanyi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Aug 19 14:49:48 2002
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[37mÄºÉ«[2;37;0m", ({ "zhanyi" }));
	set_weight(2400);
	set("item_make", 1);
	set("unit", "¼ş");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¼şÕ½ÒÂ¡£
[1;32m¶øÔÚ¶şÊ®ÄêºóµÄÒ»¸ö»Æ»èÀï
[1;32mÓĞÊ²Ã´ÊÇÓëÄÇÒ¹ÏàËÆ
[1;32m¾¹¶ûÊ¹ÄÇĞıÂÉôæÈ»À´ÁÙ
[1;32mÉ½Ãù¹ÈÓ¦¡¡Ö±±ÆÎÒĞÄ

[1;32m»Ø¹ËËùÀ´¾¶°¡
[1;32m²Ô²Ôºá×ÅµÄ´äÎ¢
[1;32mÕâ°ëÉúµÄ¿²¿À°¡
[1;32mÔÚÄºÉ«ÖĞ¾¹»¯ÎªÌğÃÛµÄÈÈÀá[2;37;0m
Õ½ÒÂÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º×ÓÁê(lilac)
");
	set("value", 2000000);
	set("point", 141);
	set("material", "stone");
	set("wear_msg", "[1;37mÔÚÒ»¸öÄêÇáµÄÒ¹Àï\n[1;37mÌı¹ıÒ»Ê×¸è\n[1;37mÇåä£²øÃà\n[1;37mÈçÉ½·ç·÷¹ı°ÙºÏ[2;37;0m\n");
	set("remove_msg", "[1;31mÔÙ¿ÊÍûÊ±È´ÉùÏ¢¼ÅÃğ\n[1;31m²»¼û×Ù¼£¡¡ÒàÎŞÀ´´¦\n[1;31m¿ÕÁôÄÇÔÂ¹âÇßÈË¼¡·ô[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
