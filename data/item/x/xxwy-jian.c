// ITEM Made by player(����:xxwy) /data/item/x/xxwy-jian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Jun 07 23:24:22 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m����[2;37;0m", ({ "jian" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ������
[1;36mһ������ͨͨ�Ľ�����������һ�磬��һ��ĳ���Ϊ����������ڣ���Ȼ�޹⣬���в�����ȱ�ڡ�[2;37;0m
�����Ͽ���һ��С�֣�����(xxwy)
");
	set("value", 2000000);
	set("point", 132);
	set("material", "stone");
	set("wield_msg", "$N��Хһ�����߶�������������[1;36m����[2;37;0m�С�\nɲ�Ǽ䣬�������[1;36m����[2;37;0m������һ��ѩ���⻪������ǧ�ٰ���ĥ�ƣ���ɼ��ˣ����и���һ�ɺ�Ȼ������[2;37;0m\n");
	set("unwield_msg", "$N��ָһ��[1;36m����[2;37;0m��һ��������[1;36m����[2;37;0m�Ͼ�Ө�׹������ʣ������ֲ�����ȱ�ڡ�[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
