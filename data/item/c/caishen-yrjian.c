// ITEM Made by player(����:caishen) /data/item/c/caishen-yrjian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri May 17 19:22:20 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[37m�׺罣[2;37;0m", ({ "yrjian" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ������
[1;37m����һ����������ı�����[2;37;0m
�����Ͽ���һ��С�֣�����(caishen)
");
	set("value", 2000000);
	set("point", 122);
	set("material", "stone");
	set("wield_msg", "[1;32m$N[1;31mһ����Х��������$n[1;31m�����ֽ������֣��򵥵Ļ��˵����ߣ�������ɱ��ȴ���㼸��������������[2;37;0m\n");
	set("unwield_msg", "[1;32m$N������$n[1;32m����������������ȴ�����ܸе���ɢ��ɱ����[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
