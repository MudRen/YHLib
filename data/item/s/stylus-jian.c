// ITEM Made by player(����:stylus) /data/item/s/stylus-jian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Oct 12 19:41:06 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m����ħ�ǽ�[2;37;0m", ({ "jian" }));
	set_weight(30000);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[36m��ɽ����[2;37;0m���ƶ��ɵ�һ������
[1;33m����ҹ������ľ���������彣��[2;37;0m
�����Ͽ���һ��С�֣�����(stylus)
");
	set("value", 2200000);
	set("point", 126);
	set("material", "stone");
	set("wield_msg", "[1;31m$N[1;31mһ����Х�����лó�һ��ͨ����ڵĳ�����\n[1;32m����г����ٱ����߽�������ǰ�������֡�[2;37;0m\n");
	set("unwield_msg", "[1;33m$N������ȥ΢΢һЦ��$n[1;33mƮɢ�����ˡ�[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
