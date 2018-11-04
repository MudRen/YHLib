// ITEM Made by player(ÃçÁé:miaomiao) /data/item/m/miaomiao-tlj.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu May 09 02:08:05 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33mÌÚÁú½£[2;37;0m", ({ "tlj" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[1;33mÒ»±ú·æÀûµÄ³¤½££¬½£ÉíÍğÈçÁ÷Ë®£¬ÒşÒşÑú×ÅÇà¹â¡£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÃçÁé(miaomiao)
");
	set("value", 2000000);
	set("point", 386);
	set("material", "stone");
	set("wield_msg", "[1;33m$Nà§µÄ³é³öÒ»±úÀû½£ÎÕÔÚÊÖÖĞ£¬½£ÉíÇà¹âµ´Ñú£¬º®Æø±ÆÈË¡£[2;37;0m\n");
	set("unwield_msg", "[1;33m$N¿ÕÎèÁËÊı¸ö½£»¨£¬½«ÌÚÁú±¦½£²å»ØÑü¼ä¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
