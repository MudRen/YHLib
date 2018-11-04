// ITEM Made by player(Ëï¾ı:sunjun) /data/item/s/sunjun-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Jun 09 09:04:23 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31mĞÄ[1;32mÄ§[1;34m½£[2;37;0m", ({ "sword" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[1;36mÕâÊÇÒ»°Ñº®¹âÉÁÉÁ£¬Í¨Ìå¾§Ó¨£¬·Ç½ğ·ÇÌú£¬¿áËÆÒ»¶Îº®±ùµÄ±¦½££¬µ±ÕæÊÇÈË¼ä¶ÀÒ»¡¢ÊÀÉÏÎŞË«µÄÒì±¦ÆæÕä¡£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºËï¾ı(sunjun)
");
	set("value", 2000000);
	set("point", 125);
	set("material", "stone");
	set("wield_msg", "[1;32mÖ»¼û[1;35m$N[1;32mÌğÌğÒ»Ğ¦£¬´Ó»³ÖĞÈ¡³öÒ»°Ñ±¦½£¡£[1;31mĞÄ[1;37mÄ§[1;34m½£[1;32mÂÔÒ»»Ó¶¯£¬ÀäÆøº®¹â£¬Á¢¿ÌÏòËÄÃæ·¢Éä¡£[2;37;0m\n");
	set("unwield_msg", "[1;31mĞÄ[1;32mÄ§[1;34m½£[1;37mÔÚ[1;35m$N[1;37mĞÄÖĞÒ»×ª£¬Õ£ÑÛ¼äÒÑ²»¼û×ÙÓ°¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
