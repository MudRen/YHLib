// ITEM Made by player(����:potian) /data/item/p/potian-knife.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Aug  8 22:58:43 2002
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[36m����[2;37;0m", ({ "knife" }));
	set_weight(30000);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[36m��ɽ����[2;37;0m���ƶ��ɵ�һ�ѵ���
����һ��Ѫ���ܵ�[36m����[2;37;0m��[2;37;0m
�����Ͽ���һ��С�֣�����(potian)
");
	set("value", 2200000);
	set("point", 134);
	set("material", "stone");
	set("wield_msg", "$N��ৡ���һ�����һ��[36m����[2;37;0m�������С�[2;37;0m\n");
	set("unwield_msg", "$N�����е�[36m����[2;37;0m��ص��ʡ�[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
