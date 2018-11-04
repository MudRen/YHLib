// ITEM Made by player(ÃçßË:mdong) /data/item/m/mdong-swordb.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Oct  1 13:48:45 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33mÌÚÁú½£[2;37;0m", ({ "swordb" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÃçßË(mdong)
");
	set("value", 2000000);
	set("point", 157);
	set("material", "stone");
	set("wield_msg", "[1;33m$Nà§µÄ³é³öÒ»±úÀû½£ÎÕÔÚÊÖÖĞ£¬½£ÉíÇà¹âµ´Ñú£¬º®Æø±ÆÈË¡£[2;37;0m\n");
	set("unwield_msg", "[1;33m$N¿ÕÎèÁËÊı¸ö½£»¨£¬½«ÌÚÁú±¦½£²å»ØÑü¼ä¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
