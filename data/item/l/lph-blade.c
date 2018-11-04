// ITEM Made by player(ÂŞÀÇ:lph) /data/item/l/lph-blade.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Oct 13 12:50:48 2002
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31mÑªÀÇÈĞ[2;37;0m", ({ "blade" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "°Ñ");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»°Ñµ¶¡£
[1;31mÕâÊÇÒ»°Ñ³äÂúÑªĞÈÎ¶µÄ±¦µ¶£¬µ¶ÉíÉÏÒ»Í·ÑªÀÇµÄÓ°×ÓÈôÒşÈôÏÖ£¬ºÃÏñ¾ÍÊÇ´«ËµÖĞµÄÑªÀÇÈĞ¡£[2;37;0m
µ¶±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÂŞÀÇ(lph)
");
	set("value", 2000000);
	set("point", 135);
	set("material", "stone");
	set("wield_msg", "[1;31mÀÇµÄÊ®´ó´¦ÊÀÕÜÑ§£º\nÎÔĞ½³¢µ¨ÖÚÀÇÒ»ĞÄ×ÔÖªÖ®Ã÷Ë³Ë®ĞĞÖÛÍ¬½øÍ¬ÍË\n±íÀïÈçÒ»Öª¼ºÖª±ËÀÇÒàÖÓÇéÊÚÀÇÒÔÓæ×ÔÓÉ¿É¹ó\n[2;37;0m\n");
	set("unwield_msg", "[1;31m$N¶ÔÔÂ³¤àÆ£º\nÎÒÊÇÒ»Æ¥À´×Ô±±·½µÄÀÇ£¡\nÑªÉ«µÄÀÇ£¡\n[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
