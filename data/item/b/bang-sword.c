// ITEM Made by player(µ¶°Ô:bang) /data/item/b/bang-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jun 12 23:21:15 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m¹Îºú×Óµ¶[2;37;0m", ({ "sword" }));
	set_weight(6750);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÀ×»ğº®¾§[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºµ¶°Ô(bang)
");
	set("value", 1600000);
	set("point", 91);
	set("material", "stone");
	set("wield_msg", "[1;36m¡°Ë¢¡±[1;37mµÄÒ»Éù£¬Ò»°Ñ[1;31mÀûÈĞ[1;37mÏòÄãÓ­ÃæÏ®À´£¬ÄãÖ»¾õµÄÏÂ°ÍÒ»Á¹£¬±£´æĞí¾ÃµÄºú×Ó²»¼ûÁË¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
