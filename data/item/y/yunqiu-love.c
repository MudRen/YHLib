// ITEM Made by player(����:yunqiu) /data/item/y/yunqiu-love.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Jun 21 21:07:57 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m����[2;37;0m", ({ "love" }));
	set_weight(1530);
	set("item_make", 1);
	set("unit", "˫");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ˫���ơ�
[1;37m������ң���͸��������������������������Ŷ��[2;37;0m
����Ե�Ͽ���һ��С�֣�����(yunqiu)
");
	set("value", 2000000);
	set("point", 120);
	set("material", "stone");
	set("wear_msg", "[1;32m����ɴ���׷��\n\n[35mֻ�ǵ�ʱ���Ȼ[2;37;0m\n");
	set("remove_msg", "[33m$N[33m������[1;37m����[2;37;0m[33m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/armor", 10);
	set("armor_prop/strike", 10);
	set("armor_prop/hand", 10);

	setup();
}

string long() { return query("long") + item_long(); }
