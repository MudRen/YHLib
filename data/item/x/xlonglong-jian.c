// ITEM Made by player(С����:xlonglong) /data/item/x/xlonglong-jian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Oct 11 21:20:42 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m������[2;37;0m", ({ "jian" }));
	set_weight(30000);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[36m��ɽ����[2;37;0m���ƶ��ɵ�һ������
�����Ͽ���һ��С�֣�С����(xlonglong)
");
	set("value", 2200000);
	set("point", 151);
	set("material", "stone");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
