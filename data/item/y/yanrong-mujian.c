// ITEM Made by player(����:yanrong) /data/item/y/yanrong-mujian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun May 26 10:46:37 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m��[1;37mң[1;32m��[2;37;0m", ({ "mujian" }));
	set_weight(6750);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m�׻𺮾�[2;37;0m���ƶ��ɵ�һ������
�����Ͽ���һ��С�֣�����(yanrong)
");
	set("value", 1600000);
	set("point", 97);
	set("material", "stone");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
