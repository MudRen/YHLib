// ITEM Made by player(��Զ��:song) /data/item/s/song-blade.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Sep  3 13:59:28 2002
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("�ֵ�[2;37;0m", ({ "blade" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ�ѵ���
����һ�����λεĸֵ�����ͨ�ٱ��ĳ���������[2;37;0m
�����Ͽ���һ��С�֣���Զ��(song)
");
	set("value", 2000000);
	set("point", 141);
	set("material", "stone");
	set("wield_msg", "$N��ৡ���һ�����һ���ֵ��������С�[2;37;0m\n");
	set("unwield_msg", "$N�����еĸֵ���ص��ʡ�[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
