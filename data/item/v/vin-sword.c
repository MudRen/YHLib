// ITEM Made by player(��ԯ��:vin) /data/item/v/vin-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed May 29 19:10:42 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37mֽ��[2;37;0m", ({ "sword" }));
	set_weight(15);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m��ֽ[2;37;0m���ƶ��ɵ�һ������
[1;37m����һ������ֽͨ���۳ɵĽ���[2;37;0m
�����Ͽ���һ��С�֣���ԯ��(vin)
");
	set("value", 1);
	set("point", 1000000);
	set("material", "stone");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
