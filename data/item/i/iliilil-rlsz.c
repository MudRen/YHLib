// ITEM Made by player(Ä§¶ÉÖÚÉú:iliilil) /data/item/i/iliilil-rlsz.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jan 20 22:26:23 2003
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;35mÈçÀ´[1;31mÉñ[1;35mÕÆ[2;37;0m", ({ "rlsz" }));
	set_weight(1530);
	set("item_make", 1);
	set("unit", "Ë«");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ë«ÌúÕÆ¡£
[1;36mÕâ¾ÍÊÇµ±ÄêÈçÀ´·ğ×æÊ¹ÓÃµÄ[1;35mÈçÀ´[1;31mÉñ[1;35mÕÆ[1;36m£¬µ±ÄêËïÎò¿Õ
¾ÍÊÇ±»ÕâË«ÊÖÕÆÑ¹ÔÚÁËÎåÖ¸É½ÏÂ£¬ÓĞ×Å²»¿ÉË¼ÒéµÄ
Á¦Á¿¡£[2;37;0m
ÌúÕÆÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÄ§¶ÉÖÚÉú(iliilil)
");
	set("value", 2000000);
	set("point", 152);
	set("material", "stone");
	set("wear_msg", "[1;31mÈÎÄãÔÙÉñÍ¨¹ã´óÒ²±ğÏëÌÓ³öÎÒµÄÕÆĞÄ¡£[2;37;0m\n");
	set("remove_msg", "[1;32mÖ»¼ûÄãÆËÔÚµØÉÏÕõÔúÁË¼¸ÏÂ£¬ÍÈÒ»Éì£¬¿ÚÖĞÅç³ö¼¸¿Ú[1;31mÏÊÑª£¬[1;32mËÀÁË£¡[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/strike", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/hand", 10);
	set("armor_prop/armor", 10);

	setup();
}

string long() { return query("long") + item_long(); }
