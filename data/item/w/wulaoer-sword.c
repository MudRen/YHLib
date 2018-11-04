// ITEM Made by player(ÎÚÀÏ¶ş:wulaoer) /data/item/w/wulaoer-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu May 02 05:12:29 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m¾ÅÉØ[1;36m¶¨Òô[1;37m½£[2;37;0m", ({ "sword" }));
	set_weight(6750);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÀ×»ğº®¾§[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[1;37m½£³¤ËÄ³ß¶ş´ç£¬ÔÚ½£¼¹Ò»±ßÑØ·æ¿Ú¿ª³ö¾Å¸ö±ÈÎ²Ö¸¼âÂÔÀ¦µÄĞ¡¿×£¬Í¨Ìå[1;36mÇà¹âÓ¨Ó¨[1;37m£¬·æ¿ìÖÁÁîÈËÄÑÒÔÏàĞÅ¡£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÎÚÀÏ¶ş(wulaoer)
");
	set("value", 2100000);
	set("point", 301);
	set("material", "stone");
	set("wield_msg", "[1;37m$N×óÊÖÒÔÖ¸»¯½££¬ÔÚĞØÇ°Æß´çÖ®´¦»­³öÒ»¸ö[1;33mÁùÃ¢ĞÇ[1;37m£¬½ô½Ó×ÅÓÒÊÖÇ°Ì½£¬´Ó[1;33mÁùÃ¢ĞÇ[1;37mÖĞÂıÂı¼À³öÒ»°Ñ$n¡£[2;37;0m\n");
	set("unwield_msg", "$n[1;37mÔÚ$NÊÖÉÏ²ü¶¯ÆğÀ´£¬ÆğÊ¼Ê±Ğ¥Ò÷ËÆÓĞÈôÎŞ£¬×ªÑÛ»¯×÷ÈçÁúĞĞÌì¼Ê¡¢µÍÇ±Ô¨º££¬Æ®ºöĞéÃìÖÁ¼«µãµÄ½£Ğ¥ÆÆ¿Õ¶øÈ¥¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
