// ITEM Made by player(³����:loupdaube) /data/item/l/loupdaube-homeland.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Dec  2 09:09:57 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m����[2;37;0m", ({ "homeland" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ������
[1;33m��ǣ���Ƶĵط����������ǹ��磡[2;37;0m
�����Ͽ���һ��С�֣�³����(loupdaube)
");
	set("value", 2000000);
	set("point", 139);
	set("material", "stone");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
