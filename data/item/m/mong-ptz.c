// ITEM Made by player(����:mong) /data/item/m/mong-ptz.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Nov 29 17:28:12 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m������[2;37;0m", ({ "ptz" }));
	set_weight(1350);
	set("item_make", 1);
	set("unit", "˫");
	set("long", "������[1;32mǬ[1;37m��[1;33mʯ[2;37;0m���ƶ��ɵ�һ˫���ơ�
[1;36m����һ�龧Ө��͸��ʯ�ƣ�ʯ��⻪��ת�����ƻ���һ�㡣[2;37;0m
����Ե�Ͽ���һ��С�֣�����(mong)
");
	set("value", 2200000);
	set("point", 194);
	set("material", "stone");
	set("wear_msg", "$N��¶�黨֮�⣬�����ʽ����ʱ�̲���ת���������ɣ�˵��������͡�\n[1;36m������[2;37;0m������$N���С�[2;37;0m\n");
	set("remove_msg", "[1;36m������[2;37;0mһ�����죬��$N������ʧ������[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/strike", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/hand", 10);

	setup();
}

string long() { return query("long") + item_long(); }
