// ITEM Made by player(���л�:jzh) /data/item/j/jzh-sanqing.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Jun 22 19:01:03 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m���彣[2;37;0m", ({ "sanqing" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ������
�����Ͽ���һ��С�֣����л�(jzh)
");
	set("value", 2000000);
	set("point", 135);
	set("material", "stone");
	set("wield_msg", "[1;34mֻ��һ����Х���ӱ�����һ�����������������˲���Ȼ����������ȫ��[2;37;0m\n");
	set("unwield_msg", "[37m�������ʣ���Ȼ������������[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
