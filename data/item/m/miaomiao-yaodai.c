// ITEM Made by player(����:miaomiao) /data/item/m/miaomiao-yaodai.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Apr  6 15:01:00 2003
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m������[2;37;0m", ({ "yaodai" }));
	set_weight(960);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ��������
[1;33mһ�������������������ơ�[2;37;0m
����Ե�Ͽ���һ��С�֣�����(miaomiao)
");
	set("value", 2000000);
	set("point", 84);
	set("material", "stone");
	set("wear_msg", "[1;33m��պ���ӧ�����ƣ�������ƣ��ƹ���翣�����һ�������������������$N���䡣[2;37;0m\n");
	set("remove_msg", "[1;33m�����������$N�����������ܳ����ȥ��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
