// ITEM Made by player(ÂåÉñ:luoshen) /data/item/l/luoshen-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon May 27 12:50:56 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31mÁ¶Óü[1;36mÇàÚ¤[1;37m½£[2;37;0m", ({ "sword" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[37mÕâÊÇÒ»°ÑÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0m[37mÎªÔ­ÁÏ£¬ÎüµØÓüÎŞÊıÔ©»ê£¬È¡ÓÄÚ¤Ö®»ğÁ¶ÖÆ¡£½£³¤Èı³ßÈı´ç£¬Õû¸ö½£
ÉñºöÃ÷ºö°µ£¬·Â·ğµØÓüµÄÔ©»êÏòÄãÕÅÑÀÎè×¦£¬Òª½«ÄãÏ²Ï¯¾í½øÈ¥Ò»Ñù£¬Äã²»½û´òÁËÒ»¸öÀäÕ½¡£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÂåÉñ(luoshen)
");
	set("value", 2000000);
	set("point", 136);
	set("material", "stone");
	set("wield_msg", "[1;37mÖ»Ìı$NÒ»ÉùÀäºß£¬$n[1;37mÇÄÈ»³öÇÊ£¬ö®Ê±Ò»¹Éº®ÒâÖ±±ÆÏòÄã£¬Í¸³¹\n·Î¸­¡£ÎŞÊıµÄÍöÁé¿ŞÌìÇÀµØ£¬·ÉÉ³×ßÊ¯£¬Ö±ÏòÄãÆË¹ıÀ´Ê¹Äã²»º®¶øÀõ¡£[2;37;0m\n");
	set("unwield_msg", "[1;37m$N³·½£»¹ÇÊ£¬Ò»¹ÉÓÄ»ğÁ²½ø½£ÇÊ£¬Äã²»½û²ÁÁË²ÁÍ·ÉÏµÄº¹£¬³¤³öÒ»¿ÚÆø¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
