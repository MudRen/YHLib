// ITEM Made by player(����:cyclone) /data/item/c/cyclone-zhan.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon May 27 13:32:38 2002
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m����ն[2;37;0m", ({ "zhan" }));
	set_weight(15000);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m����쾧[2;37;0m���ƶ��ɵ�һ�ѵ���
[1;34mһ�Ѵ�˵������ħ�������ն�����渽�������Ե���ԩ����������ǡ�[2;37;0m
�����Ͽ���һ��С�֣�����(cyclone)
");
	set("value", 4200000);
	set("point", 505);
	set("material", "tian jing");
	set("wield_msg", "[1;34m����ǰ���һ����ƥ�����һ����⣬ֱ��$n�����������ƿշ�������$N���У�[2;37;0m\n");
	set("unwield_msg", "[1;34m$n�����е�$N��ر�����ɫ���������ˣ�[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
