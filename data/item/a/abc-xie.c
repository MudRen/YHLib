// ITEM Made by player(С��:abc) /data/item/a/abc-xie.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Aug 22 22:01:27 2002
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[36m�̲�ѥ[2;37;0m", ({ "xie" }));
	set_weight(720);
	set("item_make", 1);
	set("unit", "˫");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ˫ѥ�ӡ�
[36m�����һ�����ѥ�ӡ�[2;37;0m
ѥ��Ե�Ͽ���һ��С�֣�С��(abc)
");
	set("value", 2000000);
	set("point", 69);
	set("material", "stone");
	set("wear_msg", "[33m$N[33mװ��[2;37;0m[36m�̲�ѥ[2;37;0m[33m��[2;37;0m\n");
	set("remove_msg", "[33m$N[33m������[2;37;0m[36m�̲�ѥ[2;37;0m[33m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
