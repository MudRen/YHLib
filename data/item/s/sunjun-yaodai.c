// ITEM Made by player(���:sunjun) /data/item/s/sunjun-yaodai.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Sep 26 15:55:41 2002
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m����ʯ����[2;37;0m", ({ "yaodai" }));
	set_weight(960);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ��������
����Ե�Ͽ���һ��С�֣����(sunjun)
");
	set("value", 2000000);
	set("point", 61);
	set("material", "stone");
	set("wear_msg", "[33m$N[33mװ��[1;34m����ʯ����[2;37;0m[33m��[2;37;0m\n");
	set("remove_msg", "[33m$N[33m������[1;34m����ʯ����[2;37;0m[33m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
