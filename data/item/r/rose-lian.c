// ITEM Made by player(������:rose) /data/item/r/rose-lian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri May 03 01:04:46 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m�������[2;37;0m", ({ "lian" }));
	set_weight(1350);
	set("item_make", 1);
	set("unit", "˫");
	set("long", "������[1;32mǬ[1;37m��[1;33mʯ[2;37;0m���ƶ��ɵ�һ˫���ơ�
[1;37mһ��СС�İ�ɫ���������������ţ�ɢ�������������㡣[2;37;0m
����Ե�Ͽ���һ��С�֣�������(rose)
");
	set("value", 2200000);
	set("point", 147);
	set("material", "stone");
	set("wear_msg", "[37m�������ͬ�ۣ���ǧ�깲��\n[1;36m$N[1;37m���ֽ������������������������ʢ���ɣ����������������õ������ţ���Ȼ�������С�[2;37;0m\n");
	set("remove_msg", "[1;36m$N[1;37m������̾Ϣ�ţ������������һ�����������������$N�����У�������͸���⻪˸Ȼ������һ�����顣[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/hand", 10);
	set("armor_prop/strike", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
