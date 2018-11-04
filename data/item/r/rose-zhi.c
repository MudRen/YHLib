// ITEM Made by player(ÓñÁáçç:rose) /data/item/r/rose-zhi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu May 30 03:53:56 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m²Ğ[1;36mÔÂ[1;37mÁğÁ§[2;37;0m", ({ "zhi" }));
	set_weight(3500);
	set("item_make", 1);
	set("unit", "Ì×");
	set("long", "ÕâÊÇÓÉ[1;37må¾ÓîÌì¾§[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ì×Ö¸Ì×¡£
[1;36mÎª¹Åå¾ÓñËùµñ×Á£¬Í¨Ìå±Ì²¨Á÷Ğı£¬ÔÜÆß²Ê²ĞÔÂ£¬°µÔÌĞş»Ô¡£[2;37;0m
Ö¸Ì×ÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÓñÁáçç(rose)
");
	set("value", 4200000);
	set("point", 549);
	set("material", "tian jing");
	set("wear_msg", "[1;37m$N[1;37mÓÆÓÆÒ»Éù³¤Ì¾£¬·÷ÊÖ»®¹ı£¬Ö¸¼âÈôĞÇºÓÁ÷×ª£¬ğ©²¨Ç§Àï£¬¹´³öÒ»Íä²ĞÔÂ¡£[2;37;0m\n");
	set("remove_msg", "[1;37m$N[1;32mÇáÇá¸§¹ıÖ¸¼ä£¬$n[1;32mÎ¢×÷µÍÒ÷£¬ö®Ê±¹âÃ¢¶ÙÁ²£¬ËÆÓĞÍòÇ§³îĞ÷£¬»ÓÖ®²»È¥¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/claw", 10);
	set("armor_prop/finger", 10);

	setup();
}

string long() { return query("long") + item_long(); }
