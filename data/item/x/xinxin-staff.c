// ITEM Made by player(ɽ������:xinxin) /data/item/x/xinxin-staff.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Oct  4 12:08:04 2002
#include <ansi.h>
#include <weapon.h>

inherit STAFF;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[35m����[1;36m��ħ��[2;37;0m", ({ "staff" }));
	set_weight(12000);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[36m����ʯ[2;37;0m���ƶ��ɵ�һ���ȡ�
������壬רɱ���壬���ң���Т֮��ͽ[2;37;0m
�ȱ��Ͽ���һ��С�֣�ɽ������(xinxin)
");
	set("value", 1400000);
	set("point", 83);
	set("material", "stone");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_staff(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
