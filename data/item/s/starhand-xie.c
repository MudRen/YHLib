// ITEM Made by player(������:starhand) /data/item/s/starhand-xie.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Mar 24 09:39:36 2003
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("ŷ��ƤЬ[2;37;0m", ({ "xie" }));
	set_weight(720);
	set("item_make", 1);
	set("unit", "˫");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ˫ѥ�ӡ�
ѥ��Ե�Ͽ���һ��С�֣�������(starhand)
");
	set("value", 2000000);
	set("point", 55);
	set("material", "stone");
	set("wear_msg", "[33m$N[33mװ��ŷ��ƤЬ[2;37;0m[33m��[2;37;0m\n");
	set("remove_msg", "[33m$N[33m������ŷ��ƤЬ[2;37;0m[33m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
