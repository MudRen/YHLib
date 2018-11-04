// ITEM Made by player(ÔÂÓ°á°:gaowei) /data/item/g/gaowei-jian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Sep 14 18:05:11 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m²Ô°×µÄÕıÒå[2;37;0m", ({ "jian" }));
	set_weight(15000);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;37må¾ÓîÌì¾§[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[1;32m×ÅÊÇ²ÉÔÉĞÇÖ®Ìú£¬ÊÜÖÚÉñËùÆ©ÓÓµÄÕıÒåÖ®½££¬½£Éí¹Å×¾µ­ÑÅ£¬ÖÜÉíÂú±»µñ×ÁÆæÒìµÄî¸ÎÄ·ûºÅ¡£ÔÚ°×ÒøµÄ½£ÍĞÉÏ£¬±»ïÎÈëÁËÒ»ĞĞÎÄ×Ö¡£[1;37m¶ûµÈ¼´ÈçÉñ£¬ÄÜ±çÉÆÓë¶ñ¡£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÔÂÓ°á°(gaowei)
");
	set("value", 4200000);
	set("point", 554);
	set("material", "tian jing");
	set("wield_msg", "[1;31m$NÒ»È­»÷Èë´óµØ£¬×¯ÑÏ¶ø³ÁÎÈµÄÉùÒôÂıÂıÏìÆğ¡£\n[1;32mÕÙ»½Âñ²ØÓÚÑªÂöÖĞµÄÔ¶¹ÅÊ¥Æ÷¡£\n[1;32mÊ§ÂäµÄÉñÖ®Á¦Ñ½£¬ÎÒÔÚ´ËÆóÇó´«³Ğ¡£\n[1;32mÎªÊÀÈËËùÔŞËÌµÄÃÀºÃÉúÃüÎª´ú¼Û¡£\n[1;32mË²¼ä´ïµ½ÖÁ¸ßµÄµß·å¡­¡­[2;37;0m\n");
	set("unwield_msg", "[35m$N³¤Ì¾Ò»Éù£¬ÊÖÖĞÖ®½£ÈÚÈë¿ÕÆø£¬ÏûÊ§²»¼û¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
