// ITEM Made by player(�޻�:lala) /data/item/l/lala-god.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Apr  6 07:37:50 2003
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37mʥ����а[2;37;0m", ({ "god" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ������
�����Ͽ���һ��С�֣��޻�(lala)
");
	set("value", 2000000);
	set("point", 164);
	set("material", "stone");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
