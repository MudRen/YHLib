// ITEM Made by player(���:sunjun) /data/item/s/sunjun-shoes.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Sep  5 17:26:47 2002
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m��Ь[2;37;0m", ({ "shoes" }));
	set_weight(720);
	set("item_make", 1);
	set("unit", "˫");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ˫ѥ�ӡ�
ѥ��Ե�Ͽ���һ��С�֣����(sunjun)
");
	set("value", 2000000);
	set("point", 58);
	set("material", "stone");
	set("wear_msg", "[33m$N[33mװ��[1;36m��Ь[2;37;0m[33m��[2;37;0m\n");
	set("remove_msg", "[33m$N[33m������[1;36m��Ь[2;37;0m[33m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
