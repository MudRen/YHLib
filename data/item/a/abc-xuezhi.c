// ITEM Made by player(Ğ¡¹Ï:abc) /data/item/a/abc-xuezhi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Aug 22 10:46:27 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[31mÑªÖ¸[2;37;0m", ({ "xuezhi" }));
	set_weight(1190);
	set("item_make", 1);
	set("unit", "Ì×");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ì×Ö¸Ì×¡£
[31mÕâÊÇÒ»Ö»ÊÖÖ¸£¬Íâ±íÁ÷¶¯×ÅÑªÒº°ãµÄºìÉ«¡£[2;37;0m
Ö¸Ì×ÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºĞ¡¹Ï(abc)
");
	set("value", 2000000);
	set("point", 173);
	set("material", "stone");
	set("wear_msg", "[1;31mÎ¢Ğ¦×ÅÂıÂı°ÑÓÒÊÖÊ³Ö¸·ÅÔÚ¿ÚÖĞ£¬Ö»Ìı¡°ßÇàê¡±Ò»Éù£¬ÓÒÊÖÊ³Ö¸ÒÑ¾­ÏûÊ§£¬ÏÊÑªÖ»´Ó¶Ï¿ÚÖĞÅç³ö£¬ÄãÕæÆøÒ»±ä£¬Æø¹ß×óÊÖ£¬ÂıÂıµÄ£¬Ò»¸ùÑªºìµÄÊ³Ö¸ÓÖ³öÏÖÔÚÄãÓÒÊÖÉÏ¡£[2;37;0m\n");
	set("remove_msg", "[1;32m´Ó»³ÖĞÄÃ³öÒ»Ö»¶ÏÊÖ£¬Ò»¿ÚÒ§ÏòÊ³Ö¸£¬ÓÒÊÖÕæÆøÒ»¶¯£¬ÑªÊÖÖ¸×Ô¶Ï¿ÚÒÔÉÏÍ»È»±¬ÁÑ£¬Äã×óÊÖ´Ó¿ÚÖĞÈ¡³ö¶ÏÖ¸£¬Ñ¸ËÙ°´ÔÚÉË¿ÚÉÏ£¬Ö»¼û°×¹âÒ»ÉÁ£¬¶ÏÖ¸ÍêÃÀµÄ½ÓÔÚ¶Ï¿ÚÉÏ£¬Ö»ÁôÏÂµ­µ­µÄºìË¿¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/finger", 10);
	set("armor_prop/claw", 10);

	setup();
}

string long() { return query("long") + item_long(); }
