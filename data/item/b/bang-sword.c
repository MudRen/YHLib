// ITEM Made by player(����:bang) /data/item/b/bang-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jun 12 23:21:15 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m�κ��ӵ�[2;37;0m", ({ "sword" }));
	set_weight(6750);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m�׻𺮾�[2;37;0m���ƶ��ɵ�һ������
�����Ͽ���һ��С�֣�����(bang)
");
	set("value", 1600000);
	set("point", 91);
	set("material", "stone");
	set("wield_msg", "[1;36m��ˢ��[1;37m��һ����һ��[1;31m����[1;37m����ӭ��Ϯ������ֻ�����°�һ����������õĺ��Ӳ����ˡ�[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
