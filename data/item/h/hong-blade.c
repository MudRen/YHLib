// ITEM Made by player(�캢��:hong) /data/item/h/hong-blade.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Oct 20 23:00:04 2002
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m��ϰ��[2;37;0m", ({ "blade" }));
	set_weight(6750);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[37m����[2;37;0m���ƶ��ɵ�һ�ѵ���
�����Ͽ���һ��С�֣��캢��(hong)
");
	set("value", 800000);
	set("point", 30);
	set("material", "iron");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
