// ITEM Made by player(����:daosheng) /data/item/d/daosheng-blade.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Jun 04 19:33:30 2002
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m����[2;37;0m", ({ "blade" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ�ѵ���
����������ԯŮ���[1;37m����[2;37;0m
�����Ͽ���һ��С�֣�����(daosheng)
");
	set("value", 2000000);
	set("point", 126);
	set("material", "stone");
	set("wield_msg", "[1;33mͻȻ���˵��������Ժ��и���һ�ɳ嶯��Ϊǿ�ҵİ���Χ������Χ�����ֻ�Ϊ[1;37m����[2;37;0m\n");
	set("unwield_msg", "[1;31m˿˿�����糱ˮ������ӿ����������������İ�����[1;37m����[1;31m��ˮ[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
