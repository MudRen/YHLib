// ITEM Made by player(������:rose) /data/item/r/rose-feather.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu May 23 04:47:07 2002
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m��ȸ����[2;37;0m", ({ "feather" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ�Ż��ס�
[1;37m����һ�������칬֯Ů������õ���ɴ���¡���ʽ��ӱ���£�
[1;37m����Ʈ�ݵġ��������м�ֱ�����������һ�����μ�Ʒ��[2;37;0m
����Ե�Ͽ���һ��С�֣�������(rose)
");
	set("value", 2000000);
	set("point", 111);
	set("material", "stone");
	set("wear_msg", "[1;37m$N�����չ��һ�������ѩ��Ʈ��ɴ�������������ϣ�ӳ�ĵ�\n[1;37m$N������ѩһ�㣬һ��ӯӯЦ�����ˮܽ�أ������⶯��ҡ��[2;37;0m\n");
	set("remove_msg", "[1;37m$N����Ľ���ȸ��������������[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
