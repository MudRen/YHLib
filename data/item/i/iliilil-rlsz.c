// ITEM Made by player(ħ������:iliilil) /data/item/i/iliilil-rlsz.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jan 20 22:26:23 2003
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;35m����[1;31m��[1;35m��[2;37;0m", ({ "rlsz" }));
	set_weight(1530);
	set("item_make", 1);
	set("unit", "˫");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ˫���ơ�
[1;36m����ǵ�����������ʹ�õ�[1;35m����[1;31m��[1;35m��[1;36m�����������
���Ǳ���˫����ѹ������ָɽ�£����Ų���˼���
������[2;37;0m
����Ե�Ͽ���һ��С�֣�ħ������(iliilil)
");
	set("value", 2000000);
	set("point", 152);
	set("material", "stone");
	set("wear_msg", "[1;31m��������ͨ���Ҳ�����ӳ��ҵ����ġ�[2;37;0m\n");
	set("remove_msg", "[1;32mֻ�������ڵ��������˼��£���һ�죬�����������[1;31m��Ѫ��[1;32m���ˣ�[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/strike", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/hand", 10);
	set("armor_prop/armor", 10);

	setup();
}

string long() { return query("long") + item_long(); }
