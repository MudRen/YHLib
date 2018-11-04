// ITEM Made by player(¶Î³¾°£:dcai) /data/item/d/dcai-xizhang.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Sep 27 21:40:53 2002
#include <ansi.h>
#include <weapon.h>

inherit STAFF;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m¾Å»·ÎıÕÈ[2;37;0m", ({ "xizhang" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "¸ù");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¸ùÕÈ¡£
[1;37mÕâÊÇÒ»¸ùÍ¨ÌåÆáºÚµÄÎıÕÈ£¬ÈëÊÖ¼«Îª³ÁÖØ£¬·Ç³£¼áÈÍ£¬ÄËÉÙÁÖËÂÀú´úÏà´«µÄÊ¥Îï¡£ÓĞÔÆ£ºÍ­ÏâÌúÔì¾ÅÁ¬»·£¬¾Å½ÚÏÉÌÙÓÀ×¤ÑÕ¡£[2;37;0m
ÕÈ±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º¶Î³¾°£(dcai)
");
	set("value", 2000000);
	set("point", 126);
	set("material", "stone");
	set("wield_msg", "[1;37m$NÈ¡³ö¾Å»·ÎıÕÈÎÕÓÚÊÖÖĞ£¬ö®Ê±½ğ²¨µ´Ñú£¬ÓĞÈôÆß·ğËæÉí¡£[2;37;0m\n");
	set("unwield_msg", "[1;37m$NÎ¢Î¢Ò»Ğ¦£¬½«ÊÖÖĞµÄ¾Å»·ÎıÕÈ·Å»Ø°üÄÒ¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_staff(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
