// ITEM Made by player(Ãç´ÏÃ÷:jiusword) /data/item/j/jiusword-mysword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Oct 10 22:55:13 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32mÎŞĞÎ½£Æø[2;37;0m", ({ "mysword" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
½£ÉÏÁıÕÖ×ÅÒ»²ã±¡Îí£¬ÊÇ½£·Ç½£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÃç´ÏÃ÷(jiusword)
");
	set("value", 2000000);
	set("point", 119);
	set("material", "stone");
	set("wield_msg", "[1;31m$NÎ¢Ò»ÄıÉñ£¬ÔËÆğÎŞĞÎÉñ¹¦£¬½«ÕæÆøÄı¾ÛÔÚµ¤ÌïÖ®ÖĞ£¬ÑØÆæ¾­°ËÂö±é²¼È«Éí£¡[2;37;0m\n");
	set("unwield_msg", "[1;31m$NÄ¬Äî¾ÅÑôÉñ¹¦µÄ¿Ú¾÷£ºËûÇ¿ÓÉËûÇ¿£¬Çå·ç·÷É½¸Ô¡£ËûºáÈÎËûºá£¬Ã÷ÔÂÕÕ´ó½­¡­¡­[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
