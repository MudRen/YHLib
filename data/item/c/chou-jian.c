// ITEM Made by player(������:chou) /data/item/c/chou-jian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat May 04 21:41:34 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[37m���ý�[2;37;0m", ({ "jian" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ������
[36m���ǳ����õ������[2;37;0m
�����Ͽ���һ��С�֣�������(chou)
");
	set("value", 2000000);
	set("point", 133);
	set("material", "stone");
	set("wield_msg", "[36m$N����һ������$n[36mװ�������ϡ�[2;37;0m\n");
	set("unwield_msg", "[36m$N����һ�ӣ�$n[36m�������ڡ�[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
