// ITEM Made by player(л����:china) /data/item/c/china-pifeng.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Oct 13 13:57:23 2002
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;35mħЫ����[2;37;0m", ({ "pifeng" }));
	set_weight(2400);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ��ս�¡�
[1;35m����һ��˧���ˡ�����˵����磡��������һֻ������צ�Ķ�Ы���ݴ���Ы�����˴������������벻����Ч����[2;37;0m
ս��Ե�Ͽ���һ��С�֣�л����(china)
");
	set("value", 2000000);
	set("point", 133);
	set("material", "stone");
	set("wear_msg", "[1;35m����һ˲�䣬$N�����Լ���ֱ����һ����[2;37;0m\n");
	set("remove_msg", "[1;35m����ħЫ���磬�㴹�����ߣ���Ҳ����������[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
