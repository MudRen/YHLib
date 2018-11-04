// ITEM Made by player(ÓñÁáçç:rose) /data/item/r/rose-loop.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu May 23 23:03:24 2002
#include <ansi.h>
#include <armor.h>

inherit WRISTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;35mÄıÃµÏ¼µ´[2;37;0m", ({ "loop" }));
	set_weight(600);
	set("item_make", 1);
	set("unit", "¶Ô");
	set("long", "ÕâÊÇÓÉ[2;37;0m[1;31mÑÖÂŞ³ñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¶Ô»¤Íó¡£
[1;35mÒ»Ë«Ãµ¹å»¨°ê±àÖ¯¶ø³ÉµÄÊÖïí£¬ÕóÕó»¨Ïã£¬ÎŞ²»ÈÃÈËĞÄ³ÛÉñÒ¡¡£[2;37;0m
»¤ÍóÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÓñÁáçç(rose)
");
	set("value", 2000000);
	set("point", 34);
	set("material", "stone");
	set("wear_msg", "[1;36m$N[1;35mÇáÇÉµÄ°Ñ$n[1;35m´÷ÔÚÊÖÉÏ¡£[2;37;0m\n");
	set("remove_msg", "[1;36m$N[1;35m°Ñ$n[1;35m´ÓÊÖÉÏÕªÁËÏÂÀ´¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/whip", apply_armor() / 6 + 1);
	set("armor_prop/hammer", apply_armor() / 6 + 1);
	set("armor_prop/sword", apply_armor() / 6 + 1);
	set("armor_prop/dagger", apply_armor() / 6 + 1);
	set("armor_prop/stick", apply_armor() / 6 + 1);
	set("armor_prop/finger", apply_armor() / 6 + 1);
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 6 + 1);
	set("armor_prop/strike", apply_armor() / 6 + 1);
	set("armor_prop/claw", apply_armor() / 6 + 1);
	set("armor_prop/blade", apply_armor() / 6 + 1);
	set("armor_prop/hand", apply_armor() / 6 + 1);
	set("armor_prop/club", apply_armor() / 6 + 1);
	set("armor_prop/unarmed", apply_armor() / 6 + 1);
	set("armor_prop/staff", apply_armor() / 6 + 1);
	set("armor_prop/cuff", apply_armor() / 6 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
