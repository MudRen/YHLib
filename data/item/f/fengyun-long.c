// ITEM Made by player(����:fengyun) /data/item/f/fengyun-long.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun May 19 19:20:18 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m���ý�[2;37;0m", ({ "long" }));
	set_weight(12000);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[36m����ʯ[2;37;0m���ƶ��ɵ�һ������
�����Ͽ���һ��С�֣�����(fengyun)
");
	set("value", 1400000);
	set("point", 79);
	set("material", "stone");
	set("wield_msg", "[1;31m����Ǯ�ˡ�����[1;37m���д���һ��ŭ�����ŵĻ����ɢ����æ�ó����ϵ�Ǯ�����ĵݸ�$N��[2;37;0m\n");
	set("unwield_msg", "[1;37m������������ôһ�㣬����Ϣ���ˡ���[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
