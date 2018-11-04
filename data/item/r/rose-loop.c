// ITEM Made by player(������:rose) /data/item/r/rose-loop.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu May 23 23:03:24 2002
#include <ansi.h>
#include <armor.h>

inherit WRISTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;35m��õϼ��[2;37;0m", ({ "loop" }));
	set_weight(600);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ�Ի���
[1;35mһ˫õ�廨���֯���ɵ����������㣬�޲������ĳ���ҡ��[2;37;0m
����Ե�Ͽ���һ��С�֣�������(rose)
");
	set("value", 2000000);
	set("point", 34);
	set("material", "stone");
	set("wear_msg", "[1;36m$N[1;35m���ɵİ�$n[1;35m�������ϡ�[2;37;0m\n");
	set("remove_msg", "[1;36m$N[1;35m��$n[1;35m������ժ��������[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/whip", apply_armor() / 6 + 1);
	set("armor_prop/hammer", apply_armor() / 6 + 1);
	set("armor_prop/sword", apply_armor() / 6 + 1);
	set("armor_prop/dagger", apply_armor() / 6 + 1);
	set("armor_prop/stick", apply_armor() / 6 + 1);
	set("armor_prop/finger", apply_armor() / 6 + 1);
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 6 + 1);
	set("armor_prop/strike", apply_armor() / 6 + 1);
	set("armor_prop/claw", apply_armor() / 6 + 1);
	set("armor_prop/blade", apply_armor() / 6 + 1);
	set("armor_prop/hand", apply_armor() / 6 + 1);
	set("armor_prop/club", apply_armor() / 6 + 1);
	set("armor_prop/unarmed", apply_armor() / 6 + 1);
	set("armor_prop/staff", apply_armor() / 6 + 1);
	set("armor_prop/cuff", apply_armor() / 6 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
