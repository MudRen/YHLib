// ITEM Made by player(ħ������:iliilil) /data/item/i/iliilil-armor.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Mar 24 22:20:41 2003
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m�ƽ�ʥ��[2;37;0m", ({ "armor" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ�Ż��ס�
[1;35m������Ǵ�˵�лƽ�ʥ��ʿ����[1;33m�ƽ�ʥ�¡�[2;37;0m
����Ե�Ͽ���һ��С�֣�ħ������(iliilil)
");
	set("value", 2000000);
	set("point", 139);
	set("material", "stone");
	set("wear_msg", "[33m$N[33mװ��[1;33m�ƽ�ʥ��[2;37;0m[33m��[2;37;0m\n");
	set("remove_msg", "[33m$N[33m������[1;33m�ƽ�ʥ��[2;37;0m[33m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/parry", apply_armor() / 15 + 1);
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
