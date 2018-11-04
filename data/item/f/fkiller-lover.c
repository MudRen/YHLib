// ITEM Made by player(½£ÊÖÊ¬:fkiller) /data/item/f/fkiller-lover.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu May 02 06:02:58 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37mÁùÔÂ·ÉËª[2;37;0m", ({ "lover" }));
	set_weight(6750);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÀ×»ğº®¾§[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[1;37mÕâÊÇÒ»±úĞÎÌ¬¹ÅÆÓÍ¨ÌåÑ©°×£¬½£ÉíĞŞ³¤±¡Èç²õÒí£¬½£·æÎ¢Î¢ÁıÕÖ×ÅÇàÃ¢µÄÀû½£¡£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º½£ÊÖÊ¬(fkiller)
");
	set("value", 2100000);
	set("point", 133);
	set("material", "stone");
	set("wield_msg", "[1;37m$NÇáÇáÒ»Éù³¤Ì¾£¬»º»ºµØ´Ó½£ÇÊÖĞ½«±¦½£°Î³ö£¬¶ÙÊ±ÌìµØ¼äÃÖÂş×ÅÒ»¹ÉÁîÈËÖÏÏ¢µÄÉ±Æø£¬\nÔÚ³¡ÖÚÈËÖ»¾õº®Æø±ÆÈËÃ«¹Çã¤È»£¬²»ÓÉ¸ĞÌ¾ÊÀ¼ä¾¹ÓĞÈç´ËÀûÆ÷¡£[2;37;0m\n");
	set("unwield_msg", "[1;37m$NÊÖÍóÎ¢Î¢Ò»Õğ±¦½£ÒÑÈ»ÈëÇÊ£¬ËÄÖÜÉñÃØÉ±ÆøË²¼äµ´È»ÎŞ´æ£¬\nÔÚ³¡ÖÚÈËĞÄÍ·Ò»ËÉ£¬²»ÓÉ³¤ĞêÒ»Éù¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
