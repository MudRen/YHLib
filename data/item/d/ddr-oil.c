// ITEM Made by player(����:ddr) /data/item/d/ddr-oil.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jul 24 12:25:13 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m��ͭ[1;36m����[2;37;0m", ({ "oil" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ������
������ʲô�����ٿ��Ͱ���ȵ�[2;37;0m
�����Ͽ���һ��С�֣�����(ddr)
");
	set("value", 2000000);
	set("point", 90);
	set("material", "stone");
	set("wield_msg", "����ɽ��[2;37;0m\n");
	set("unwield_msg", "����ɽ��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
