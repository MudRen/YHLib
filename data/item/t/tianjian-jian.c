// ITEM Made by player(Óî»ÊÉñ°Á:tianjian) /data/item/t/tianjian-jian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Nov  5 13:30:27 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[35mÑª×ÏµÄ²Ã¾ö[2;37;0m", ({ "jian" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[1;31mÕâ°Ñ½£³¤ËÄ³ß£¬ÖÜÉí²¼ÂúÇ³Ç³µÄÑªÎÆ£¬òêÑÑÁ÷×ªµ½½£±ú´¦£¬³ÊÏÖ³ö¹Å¹ÖµÄÍ¼°¸¡£ÔÚ×Ï½ğµÄ½£ÍĞÉÏÓÃµñ×ÁÁË¼¸¸öÑªÉ«µÄ×Ö£º
[35m¶ûµÈĞÄÈçÄ§£¬ÑªÉ«ÎÆĞŞÂŞ¡£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÓî»ÊÉñ°Á(tianjian)
");
	set("value", 2000000);
	set("point", 129);
	set("material", "stone");
	set("wield_msg", "[1;31m$NÊÖÖĞÍ»È»³ÊÏÖÒìÑùµÄ¹â»ª£¬¹îÒìµÄÉùÒôÕóÕóÏìÆğ¡£\n[35mÕÙ»½Âñ²ØÓëÑªÂöÖĞµÄÔ¶¹ÅÊ¥Æ÷¡£\n[35mÊ§ÂäµÄÑªÉ«Ö®Á¦°¡£¬ÎÒÔÚ´ËÆóÇó´«³Ğ¡£\n[35mÒÔÎÒµÄÉúÃüºÍ×îÃÀÀöµÄË²¼äÎª´ú¼Û¡£\n[1;31mÒ»°Ñ×ÏÉ«µÄ³¤½£Æ¾¿Õ³öÏÖÔÚ$NÊÖÖĞ¡£[2;37;0m\n");
	set("unwield_msg", "[1;35m¹â»ª¾¡È¥£¬$NÊÖÖĞµÄ×ÏÉ«³¤½££¬Æ¾¿ÕÏûÊ§²»¼û£¬ÈçÈÜÈë¿ÕÆøÒ»°ã¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
