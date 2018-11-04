// ITEM Made by player(����:mdong) /data/item/m/mdong-clotha.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Jun 27 17:41:53 2002
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m���ϱ���[2;37;0m", ({ "clotha" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ�Ż��ס�
����Ե�Ͽ���һ��С�֣�����(mdong)
");
	set("value", 2000000);
	set("point", 108);
	set("material", "stone");
	set("wear_msg", "[33m$N[33mװ��[1;37m���ϱ���[2;37;0m[33m��[2;37;0m\n");
	set("remove_msg", "[33m$N[33m������[1;37m���ϱ���[2;37;0m[33m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
