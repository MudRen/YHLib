// ITEM Made by player(ºúĞĞ:qiangren) /data/item/q/qiangren-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat May 04 22:46:54 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[36m°ÁÆø³åÌì½£[2;37;0m", ({ "sword" }));
	set_weight(30000);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[2;37;0m[36mÌìÉ½ĞşÌú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[1;36m½£³¤Èı³ß£¬¼¯ÌìµØÖ®ÁéÆø£¬ÓÉ½£Ê¦¸É½«ËùÖı¡£½£¼¹¿ÌÓĞ¹ÅÎÄ£¬½£·æÇà¹âµ´Ñú£¬·æÀûÎŞ±È¡£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ººúĞĞ(qiangren)
");
	set("value", 2200000);
	set("point", 207);
	set("material", "stone");
	set("wield_msg", "[1;36m$NÒ»ÉùÇåĞ¥£¬´ÓÑü¼ä³é³öÒ»±ú°ÁÆø³åÌì½££¬½£¹âÈçË®£¬º®ÆøÆËÃæ¶øÖÁ¡£[2;37;0m\n");
	set("unwield_msg", "[1;36m$NÓÆÓÆÒ»Éù³¤Ì¾£¬ÇáÇáÊÃÈ¥°ÁÆø³åÌì½£½£·æÉÏµÄÑª¼££¬·´ÊÖ²åÈë½£ÇÊ¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
