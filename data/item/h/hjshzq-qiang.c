// ITEM Made by player(���:hjshzq) /data/item/h/hjshzq-qiang.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Jun 18 19:04:26 2002
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m����ǽ[2;37;0m", ({ "qiang" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ�Ż��ס�
[1;31m���Ƿ��������ף�զһ����Ȼ�Ƕ¸�ǽ��������˼�飡Ҳ��ǽ�ڲ�����õķ��߰ɣ���[2;37;0m
����Ե�Ͽ���һ��С�֣����(hjshzq)
");
	set("value", 2000000);
	set("point", 105);
	set("material", "stone");
	set("wear_msg", "[1;31mͻȻֻ��$N���Լ���Χ������һ�¸�ǽ��������$N�ķ���֮���ɣ�[2;37;0m\n");
	set("remove_msg", "[1;31m$N������Χһ�ж���ȫ�ˣ������ϰѷ���ǽ���ˣ�[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
