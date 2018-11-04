// ITEM Made by player(ÂåÉñ:luoshen) /data/item/l/luoshen-hand.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue May 14 11:40:35 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37mº®±ù[1;31mÁÒÑæ[1;36mÕÆ[2;37;0m", ({ "hand" }));
	set_weight(1530);
	set("item_make", 1);
	set("unit", "Ë«");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ë«ÌúÕÆ¡£
[1;37mÕâÊÇÖı½£´óÊ¦¸É½«İÍÈ¡[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m[1;37m±ùÓñ£¬¼³Ìì£¬µØ£¬ÈËÈıÕßÖ®Æø£¬ÒÔ[1;31mÈıÎ¶Õæ»ğ[1;37mÁ·¾Í¶ø³ÉµÄ¡£
[1;37mº®±ù[1;31mÁÒÑæ[1;36mÕÆ[2;37;0m[1;37m±íÃæÒ»²ãµ­µ­µÄÎíÆø£¬Áò¹âÒì²Ê£¬¾§Ó¨ÌŞÍ¸¡£[2;37;0m
ÌúÕÆÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÂåÉñ(luoshen)
");
	set("value", 2000000);
	set("point", 126);
	set("material", "stone");
	set("wear_msg", "[37m$Nµ­µ­Ò»Ğ¦£¬Ë«ÊÖ»º»ºÉì³ö£¬Í»È»ÄãÑÛÇ°Ò»»¨£¬$NÊÖÉÏÒÑ¾­¶àÁËÒ»Ë«$n[37m£¬¾§Ó¨ÌŞÍ¸£¬Òì²ÊÁ÷¶¯¡£[2;37;0m\n");
	set("remove_msg", "[37m$NË«ÊÖ¹éÂ££¬½«$n[37mÊÕÓÚÅÛĞäÖ®ÖĞ£¬¸ºÊÖ¶øÁ¢£¬Íş·çÁİÁİ¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/hand", 10);
	set("armor_prop/strike", 10);

	setup();
}

string long() { return query("long") + item_long(); }
