// ITEM Made by player(�ξ���:wudanji) /data/item/w/wudanji-xie.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Nov 13 11:40:10 2002
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("��ţ[2;37;0m", ({ "xie" }));
	set_weight(720);
	set("item_make", 1);
	set("unit", "˫");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ˫ѥ�ӡ�
ѥ��Ե�Ͽ���һ��С�֣��ξ���(wudanji)
");
	set("value", 2000000);
	set("point", 53);
	set("material", "stone");
	set("wear_msg", "[33m$N[33mװ����ţ[2;37;0m[33m��[2;37;0m\n");
	set("remove_msg", "[33m$N[33m��������ţ[2;37;0m[33m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
