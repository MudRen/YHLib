// ITEM Made by player(���:lingling) /data/item/l/lingling-jian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue May 21 16:30:35 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m�����[2;37;0m", ({ "jian" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ������
[1;32mһ��СС���������[2;37;0m
�����Ͽ���һ��С�֣����(lingling)
");
	set("value", 2000000);
	set("point", 121);
	set("material", "stone");
	set("wield_msg", "����һ��СС����$N��[2;37;0m\n");
	set("unwield_msg", "��СС����$N�Ž����[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
