// ITEM Made by player(��Ҷ:leaf) /data/item/l/leaf-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Dec  8 16:12:44 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m����[2;37;0m", ({ "sword" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ������
[1;34m�紵�嶯[2;37;0m
�����Ͽ���һ��С�֣���Ҷ(leaf)
");
	set("value", 2000000);
	set("point", 116);
	set("material", "stone");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
