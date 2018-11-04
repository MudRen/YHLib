// ITEM Made by player(���϶�:wulaoer) /data/item/w/wulaoer-unarmed.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jul 15 20:47:40 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m����[2;37;0m", ({ "unarmed" }));
	set_weight(1530);
	set("item_make", 1);
	set("unit", "˫");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ˫���ơ�
[1;37m��[2;37;0m��[1;31m����[2;37;0m��[1;37m�û����ɵ�һ�����ף�������Լɢ���ŵ����Ĺ�â��[2;37;0m
����Ե�Ͽ���һ��С�֣����϶�(wulaoer)
");
	set("value", 2000000);
	set("point", 300);
	set("material", "stone");
	set("wear_msg", "[1;37m$N�ӱ��������߰ѽ�������һ��[2;37;0m��[1;31m��[2;37;0m��[1;37m���������̹⻯��һ�����ס�[2;37;0m\n");
	set("remove_msg", "[1;31m�������ľ�����[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/hand", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/strike", 10);

	setup();
}

string long() { return query("long") + item_long(); }
