// ITEM Made by player(��ӳѩ:lrl) /data/item/l/lrl-blade.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Apr 26 21:05:43 2002
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m���±���[2;37;0m", ({ "blade" }));
	set_weight(30000);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[36m��ɽ����[2;37;0m���ƶ��ɵ�һ�ѵ���
[1;36m����һ���������µı�����������������ɭɭ�������ޱȡ�[2;37;0m
�����Ͽ���һ��С�֣���ӳѩ(lrl)
");
	set("value", 2200000);
	set("point", 120);
	set("material", "stone");
	set("wield_msg", "[1;36m$N������������µĳ�������ʱֻ���������ˣ�������ˮ����ת������[2;37;0m\n");
	set("unwield_msg", "[1;36m$N������Х�����ип��������±�����ص��ʡ�[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
