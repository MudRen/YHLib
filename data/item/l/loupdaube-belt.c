// ITEM Made by player(³����:loupdaube) /data/item/l/loupdaube-belt.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Nov 28 09:52:34 2002
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[35m����[2;37;0m", ({ "belt" }));
	set_weight(960);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ��������
[35m�̣ϣգС��ģ����գ£�[2;37;0m
����Ե�Ͽ���һ��С�֣�³����(loupdaube)
");
	set("value", 2000000);
	set("point", 55);
	set("material", "stone");
	set("wear_msg", "[33m$N[33mװ��[2;37;0m[35m����[2;37;0m[33m��[2;37;0m\n");
	set("remove_msg", "[33m$N[33m������[2;37;0m[35m����[2;37;0m[33m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
