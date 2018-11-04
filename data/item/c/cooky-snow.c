// ITEM Made by player(Ìğ±ı:cooky) /data/item/c/cooky-snow.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Oct 10 12:21:45 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36móãâù[2;37;0m", ({ "snow" }));
	set_weight(1190);
	set("item_make", 1);
	set("unit", "Ì×");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ì×Ö¸Ì×¡£
[1;36mÏª±ß°×ğØ¡£À´Îá¸æÈê¡£ÏªÀïÓã¶ù¿°Êı¡£Ö÷ÈËÁ¯ÈêÈêÁ¯Óã£¬ÒªÎïÎÒ¡¢ĞÀÈ»Ò»´¦¡£
[1;36m°×É³Ô¶ÆÖ¡£ÇàÄà±ğä¾¡£Ê£ÓĞÏºÌøöúÎè¡£ÈÎ¾ı·ÉÈ¥±¥Ê±À´£¬¿´Í·ÉÏ¡¢·ç´µÒ»ÂÆ¡£[2;37;0m
Ö¸Ì×ÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÌğ±ı(cooky)
");
	set("value", 2000000);
	set("point", 144);
	set("material", "stone");
	set("wear_msg", "[1;36mÍí·ç´µÓê£¬Õ½ĞÂºÉ¡¢ÉùÂÒÃ÷Öé²Ôèµ¡£Ë­°ÑÏãŞÆÊÕ±¦¾µ£¬ÔÆ½õºìº­ºş±Ì¡£\n[1;36m·ÉÄñ·­¿Õ£¬ÓÎÓã´µÀË£¬¹ß³ÃóÏ¸èÏ¯¡£×øÖĞºÀÆø£¬¿´¹«Ò»ÒûÇ§Ê¯¡£[2;37;0m\n");
	set("remove_msg", "[1;36mÒ£Ïë´¦Ê¿·çÁ÷£¬º×ËæÈËÈ¥£¬ÀÏ×÷·ÉÏÉ²®¡£Ã©ÉáÊèÀé½ñÔÚ·ñ£¬ËÉÖñÒÑ·Ç³ëÎô¡£\n[1;36mÓûËµµ±Äê£¬ÍûºşÂ¥ÏÂ£¬Ë®ÓëÔÆ¿íÕ­¡£×íÖĞĞİÎÊ£¬¶Ï³¦ÌÒÒ¶ÏûÏ¢¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/claw", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/finger", 10);

	setup();
}

string long() { return query("long") + item_long(); }
