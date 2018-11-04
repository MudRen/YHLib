// ITEM Made by player(ÔÂÓ°á°:gaowei) /data/item/g/gaowei-hundun.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Sep 25 02:53:38 2002
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[35m»ìãç[2;37;0m", ({ "hundun" }));
	set_weight(2550);
	set("item_make", 1);
	set("unit", "¶¥");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¶¥Í·¿ø¡£
[35mÕâÊÇÉÏ¹ÅÉñÆ÷Ö®Ò»£¬ÉÁË¸×ÅÕóÕó×Ï¹âµÄÍ·½í£¬²»ÖªÓÉºÎÎïËùÖı£¬±¦µ¶Àû½£Ò²²»ÄÜÉËËü·ÖºÁ¡£[2;37;0m
Í·¿øÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÔÂÓ°á°(gaowei)
");
	set("value", 2000000);
	set("point", 58);
	set("material", "stone");
	set("wear_msg", "[35m$NÖÜÉíÍ»È»±»Ò»ÍÅ»ì»ì³Á³ÁµÄÑÌÎíËù°üÎ§£¬µ±ÑÌÎíÏûÊ§µÄÊ±ºò£¬ËûÍ·ÉÏÒÑ¾­´ø×ÅÒ»ÌõÒşÒşÁ÷Â¶³ö×Ï¹âµÄÍ·½í¡£[2;37;0m\n");
	set("remove_msg", "[1;36mÒ»µÀÇà¹â»®¹ı£¬$NÍ·ÉÏµÄÍ·½íËÆºõÈÜÈë¿ÕÆøÏûÊ§²»¼ûÁË¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
