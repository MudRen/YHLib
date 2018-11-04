// ITEM Made by player(Ìğ±ı:cooky) /data/item/c/cooky-flower.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Oct 20 07:53:29 2002
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37móãÎè[2;37;0m", ({ "flower" }));
	set_weight(2400);
	set("item_make", 1);
	set("unit", "¼ş");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¼şÕ½ÒÂ¡£
[1;37mÏãØÌÄıĞßÒ»Ğ¦¿ª¡£ÁøÑüÈç×íÅ¯Ïà°¤¡£ÈÕ³¤´ºÀ§ÏÂÂ¥Ì¨¡£
[1;37mÕÕË®ÓĞÇéÁÄÕû÷Ş£¬ÒĞÀ»ÎŞĞ÷¸ü¶µĞ¬¡£ÑÛ±ßÇ£ÏµÀÁ¹éÀ´¡£[2;37;0m
Õ½ÒÂÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÌğ±ı(cooky)
");
	set("value", 2000000);
	set("point", 90);
	set("material", "stone");
	set("wear_msg", "[1;37mÑ°Ñ°ÃÙÃÙ£¬ÀäÀäÇåÇå£¬ÆàÆà²Ò²ÒÆİÆİ¡£\n[1;37mÕ§Å¯»¹º®Ê±ºò£¬×îÄÑ½«Ï¢¡£Èı±­Á½Õµµ­¾Æ£¬ÔõµĞËû¡¢ÍíÀ´·ç¼±¡£\n[1;37mÑã¹ıÒ²£¬ÕıÉËĞÄ£¬È´ÊÇ¾ÉÊ±ÏàÊ¶¡£[2;37;0m\n");
	set("remove_msg", "[33m$N[33mÍÑÏÂÁË[1;37móãÎè[2;37;0m[33m¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
