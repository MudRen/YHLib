// ITEM Made by player(ÎŞÃû:xxwy) /data/item/x/xxwy-jian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Jun 07 23:24:22 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36mº®Óñ½£[2;37;0m", ({ "jian" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;36mÀë[1;31m»ğ[1;36mĞş[1;37m±ù[1;36mÓñ[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[1;36mÒ»±úÆÕÆÕÍ¨Í¨µÄ½£¡£½£³¤Èı³ßÒ»´ç£¬½ÏÒ»°ãµÄ³¤½£Îª³¤¡£½£Éí÷îºÚ£¬÷öÈ»ÎŞ¹â£¬½£ÈĞ²¼ÂúÁËÈ±¿Ú¡£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÎŞÃû(xxwy)
");
	set("value", 2000000);
	set("point", 132);
	set("material", "stone");
	set("wield_msg", "$N³¤Ğ¥Ò»Éù£¬´ß¶¯µÄÄÚÁ¦£¬¹àÈë[1;36mº®Óñ½£[2;37;0mÖĞ¡£\nÉ²ÄÇ¼ä£¬ºÚ÷î÷îµÄ[1;36mº®Óñ½£[2;37;0m£¬±¬³ÉÒ»ÍÅÑ©ÁÁ¹â»ª£¬»ĞÈôÇ§°Ù°×ÓñÄ¥ÖÆ£¬¹â¿É¼øÈË£¬ÄÚÖĞ¸üÓĞÒ»¹ÉºÆÈ»ÏÉÆø¡£[2;37;0m\n");
	set("unwield_msg", "$NÉìÖ¸Ò»µ¯[1;36mº®Óñ½£[2;37;0m£¬Ò»ÉùÇåÒ÷¡£[1;36mº®Óñ½£[2;37;0mÉÏ¾§Ó¨°×¹âÖğ½¥ÏûÍÊ£¬½£ÈĞÓÖ²¼ÂúÁËÈ±¿Ú¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
