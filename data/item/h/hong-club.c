// ITEM Made by player(�캢��:hong) /data/item/h/hong-club.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Oct 26 15:28:45 2002
#include <ansi.h>
#include <weapon.h>

inherit CLUB;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m����[2;37;0m", ({ "club" }));
	set_weight(6750);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[37m����[2;37;0m���ƶ��ɵ�һ������
�����Ͽ���һ��С�֣��캢��(hong)
");
	set("value", 800000);
	set("point", 37);
	set("material", "iron");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_club(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
