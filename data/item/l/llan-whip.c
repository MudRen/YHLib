// ITEM Made by player(����:llan) /data/item/l/llan-whip.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Oct 12 20:55:21 2002
#include <ansi.h>
#include <weapon.h>

inherit WHIP;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[31m���ݿ���[2;37;0m", ({ "whip" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ���ޡ�
���������޳����ƶ��ɵĳ��ޡ�����������������������[2;37;0m
�ޱ��Ͽ���һ��С�֣�����(llan)
");
	set("value", 2000000);
	set("point", 132);
	set("material", "stone");
	set("wield_msg", "[31mɱ���㣬����[2;37;0m\n");
	set("unwield_msg", "[31m���������ͷһ�ã�����[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_whip(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
