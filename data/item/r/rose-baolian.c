// ITEM Made by player(������:rose) /data/item/r/rose-baolian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Apr  7 09:42:45 2003
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m�߲ʱ���[2;37;0m", ({ "baolian" }));
	set_weight(1530);
	set("item_make", 1);
	set("unit", "˫");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ˫���ơ�
[1;32mһ�䵱�����������ժ����ɫ����[2;37;0m
����Ե�Ͽ���һ��С�֣�������(rose)
");
	set("value", 2000000);
	set("point", 210);
	set("material", "stone");
	set("wear_msg", "[33m$N[33mװ��[1;32m�߲ʱ���[2;37;0m[33m��[2;37;0m\n");
	set("remove_msg", "[33m$N[33m������[1;32m�߲ʱ���[2;37;0m[33m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/strike", 10);
	set("armor_prop/hand", 10);

	setup();
}

string long() { return query("long") + item_long(); }
