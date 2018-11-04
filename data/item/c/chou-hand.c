// ITEM Made by player(������:chou) /data/item/c/chou-hand.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu May 30 10:04:15 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m��ȭ[2;37;0m", ({ "hand" }));
	set_weight(1530);
	set("item_make", 1);
	set("unit", "˫");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ˫���ơ�
[1;32m���ǳ����õ�[1;37m��ȭ[1;32m��[2;37;0m
����Ե�Ͽ���һ��С�֣�������(chou)
");
	set("value", 2000000);
	set("point", 151);
	set("material", "stone");
	set("wear_msg", "[1;32m$N����[1;37m��ȭ[1;32m������׼�������ˡ�[2;37;0m\n");
	set("remove_msg", "[1;32m$N�������˰�[1;37m��ȭ[1;32m����������[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/strike", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/hand", 10);

	setup();
}

string long() { return query("long") + item_long(); }
