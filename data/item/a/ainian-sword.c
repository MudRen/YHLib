// ITEM Made by player(���ΰ�:ainian) /data/item/a/ainian-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Aug 16 19:17:07 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[32m����[2;37;0m", ({ "sword" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ������
[32m����һ����ͨ�ľ��ֽ���һ��Ľ��Ͷ�����˽���[2;37;0m
�����Ͽ���һ��С�֣����ΰ�(ainian)
");
	set("value", 2000000);
	set("point", 126);
	set("material", "stone");
	set("wield_msg", "[32m$N��ৡ���һ�����һ�������������С�[2;37;0m\n");
	set("unwield_msg", "[32m$N�����еĳ�����ؽ��ʡ�[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
