// ITEM Made by player(ÄÉÀ¼ÈİÇé:rongqing) /data/item/r/rongqing-bpjian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Jun 28 22:22:03 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m±ùÆÇº®¹â½£[2;37;0m", ({ "bpjian" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[1;33mÍòÔØĞş±ù»ğìÍÈÛ£¬ÆüÑªÄı±ÌÖıº®·æ¡£Ë­ÇæÓñÈĞµ±¿ÕÎè£¬·ïÒè¾ÅÌìÃÙÎŞ×Ù¡£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÄÉÀ¼ÈİÇé(rongqing)
");
	set("value", 2000000);
	set("point", 135);
	set("material", "stone");
	set("wield_msg", "[1;36m¡°ïÏ¡±µÄÒ»ÉùÁúÒ÷£¬$NÊÖÖĞ¾ªÏÖÒ»ÊøÈı³ßº®±ù£¬Ï¸¹ÛÖ®ÏÂ£¬ºÕÈ»±ãÊÇÃû¶¯½­ºşµÄ¡°±ùÆÇº®¹â½£¡±¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
