// ITEM Made by player(������:rose) /data/item/r/rose-zhi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu May 30 03:53:56 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m��[1;36m��[1;37m����[2;37;0m", ({ "zhi" }));
	set_weight(3500);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m����쾧[2;37;0m���ƶ��ɵ�һ��ָ�ס�
[1;36mΪ�������������ͨ��̲����������߲ʲ��£��������ԡ�[2;37;0m
ָ��Ե�Ͽ���һ��С�֣�������(rose)
");
	set("value", 4200000);
	set("point", 549);
	set("material", "tian jing");
	set("wear_msg", "[1;37m$N[1;37m����һ����̾�����ֻ�����ָ�����Ǻ���ת��𩲨ǧ�����һ����¡�[2;37;0m\n");
	set("remove_msg", "[1;37m$N[1;32m���ḧ��ָ�䣬$n[1;32m΢����������ʱ��â������������ǧ��������֮��ȥ��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/claw", 10);
	set("armor_prop/finger", 10);

	setup();
}

string long() { return query("long") + item_long(); }
