// ITEM Made by player(�鸣:lingfu) /data/item/l/lingfu-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri May 17 14:03:43 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("����[2;37;0m", ({ "sword" }));
	set_weight(30000);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[36m��ɽ����[2;37;0m���ƶ��ɵ�һ������
�����Ͽ���һ��С�֣��鸣(lingfu)
");
	set("value", 2200000);
	set("point", 136);
	set("material", "stone");
	set("wield_msg", "$N��ৡ���һ�����һ�������������С�[2;37;0m\n");
	set("unwield_msg", "$N�����еĳ�����ؽ��ʡ�[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
