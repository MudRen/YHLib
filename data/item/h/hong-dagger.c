// ITEM Made by player(�캢��:hong) /data/item/h/hong-dagger.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Oct 20 23:09:22 2002
#include <ansi.h>
#include <weapon.h>

inherit DAGGER;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m��ϰذ��[2;37;0m", ({ "dagger" }));
	set_weight(1350);
	set("item_make", 1);
	set("unit", "֧");
	set("long", "������[37m����[2;37;0m���ƶ��ɵ�һ֧�̱���
�̱����Ͽ���һ��С�֣��캢��(hong)
");
	set("value", 800000);
	set("point", 30);
	set("material", "iron");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ֧[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_dagger(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
