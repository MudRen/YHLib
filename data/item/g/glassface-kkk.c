// ITEM Made by player(ҶС��:glassface) /data/item/g/glassface-kkk.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Aug  5 22:52:22 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("��[2;37;0m", ({ "kkk" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[33m�ڽ��[2;37;0m���ƶ��ɵ�һ������
�����Ͽ���һ��С�֣�ҶС��(glassface)
");
	set("value", 1);
	set("point", 125);
	set("material", "stone");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
