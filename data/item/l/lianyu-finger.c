// ITEM Made by player(����:lianyu) /data/item/l/lianyu-finger.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Aug 25 11:36:36 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37mһָ[1;31m�ϳ�[2;37;0m", ({ "finger" }));
	set_weight(1190);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ��ָ�ס�
[1;36mǧ��������ƶ��ɵİ�ָ��ָ��һ����[1;31m��[1;36m����һ����[1;37m��[1;36m��������[1;31m��[1;32m��[1;33m��[1;34m��[1;36m֮����[2;37;0m
ָ��Ե�Ͽ���һ��С�֣�����(lianyu)
");
	set("value", 2000000);
	set("point", 144);
	set("material", "stone");
	set("wear_msg", "[1;31mʮ��������ãã����˼����������\n[1;32mǧ��·ء��޴�������\n[1;33m��ʹ���Ӧ��ʶ�������桪����˪\n[2;37;0m\n");
	set("remove_msg", "[1;35mҹ�����κ����硪С����������ױ\n[1;36m������ԡ�Ω����ǧ��\n[1;37m�ϵ����곦�ϴ�������ҹ�����ɸ�\n[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/finger", 10);
	set("armor_prop/claw", 10);

	setup();
}

string long() { return query("long") + item_long(); }
