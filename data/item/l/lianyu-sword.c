// ITEM Made by player(����:lianyu) /data/item/l/lianyu-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Aug 20 11:23:42 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m���̶���[2;37;0m", ({ "sword" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ������
[1;31m�һ�Ӱ�����[1;36m�̺�����������[2;37;0m
�����Ͽ���һ��С�֣�����(lianyu)
");
	set("value", 2000000);
	set("point", 144);
	set("material", "stone");
	set("wield_msg", "[1;32m��ָ��ͷ�����£�������������Ӱ[2;37;0m\n");
	set("unwield_msg", "[1;32m���������������Խ�ͤ��������[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
