// ITEM Made by player(���ΰ�:ainian) /data/item/a/ainian-sworda.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Mar 22 11:23:16 2003
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("����[2;37;0m", ({ "sworda" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;35m����[2;37;0m���ƶ��ɵ�һ������
����һ����ͨ�ľ��ֽ���һ��Ľ��Ͷ�����˽���[2;37;0m
�����Ͽ���һ��С�֣����ΰ�(ainian)
");
	set("value", 2200000);
	set("point", 195);
	set("material", "magic stone");
	set("wield_msg", "$N��ৡ���һ�����һ�������������С�[2;37;0m\n");
	set("unwield_msg", "$N�����еĳ�����ؽ��ʡ�[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
