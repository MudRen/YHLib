// ITEM Made by player(ÄÉÀ¼:mong) /data/item/m/mong-tjian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jul  1 23:40:47 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37mÎÊÌì½£[2;37;0m", ({ "tjian" }));
	set_weight(15000);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;37må¾ÓîÌì¾§[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[1;36mÒ»¿é´¿°×É«½£ĞÎË®¾§£¬¾§Ó¨ÌŞÍ¸£¬ÎŞÏ¾µÄ±íÃæÉä³öÒ«ÑÛµÄ¹âÔó¡£ÆäÖĞ·Â·ğÔÌ²Ø×ÅÇ§Ç§ÍòÍòµÄÉúÃü£¬
ÉúÃüÁ÷¶¯²»Ï¢£¬É¢·¢³öÓîÖæµÄÁ¦Á¿¡£Õâ±ãÊÇ´«ËµÖĞµÄÖÁ±¦[1;37mÎÊÌì½£[2;37;0m£¬[1;36mÏà´«Ö»ÓĞÔÚÌì¹¬ÖĞ²Å»á³öÏÖ¡£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÄÉÀ¼(mong)
");
	set("value", 4200000);
	set("point", 481);
	set("material", "tian jing");
	set("wield_msg", "[1;36mÌìµØÉ«±äÖĞ£¬´óµØºäÈ»¾ŞÏì£¬·Â·ğÓĞÎïÅØÏøÈçÀ×¡£\n$NÑöÊ×ÍûÌì£¬Á³É«É·°×ÈçÑ©£¬´óºÈÉùÖĞ£¬[1;37mÎÊÌì½£[2;37;0m[1;36mÓ­·ç³öÇÊ£¬¹â»ª´óÊ¢ÖĞ£¬°×ºç¹áÈÕ¶øÈë¡£[2;37;0m\n");
	set("unwield_msg", "[1;36m$NÑöÊ×ÍûÌì¡£½£ÒÑ¹éÇÊ£¬¶øĞÄÈÔÎÊÌì¡£\n[1;37m¡°»ÊÌìÖ®²»´¿ÃüÙâ£¬ºÎ°ÙĞÕÖ®Õğí©£¡¡±[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
