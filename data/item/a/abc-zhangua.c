// ITEM Made by player(С��:abc) /data/item/a/abc-zhangua.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue May 07 10:36:09 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[36mն�Ͻ�[2;37;0m", ({ "zhangua" }));
	set_weight(30000);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[36m��ɽ����[2;37;0m���ƶ��ɵ�һ������
�˽�����˵�������ֻ������ն�ϡ�[2;37;0m
�����Ͽ���һ��С�֣�С��(abc)
");
	set("value", 2200000);
	set("point", 400);
	set("material", "stone");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
