// ITEM Made by player(С��:abc) /data/item/a/abc-qiegua.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Apr 28 11:58:58 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("�йϽ�[2;37;0m", ({ "qiegua" }));
	set_weight(6750);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[37m����[2;37;0m���ƶ��ɵ�һ������
�˽�һ���쳣�����������йϿ϶�����[2;37;0m
�����Ͽ���һ��С�֣�С��(abc)
");
	set("value", 800000);
	set("point", 39);
	set("material", "iron");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
