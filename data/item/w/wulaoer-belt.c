// ITEM Made by player(���϶�:wulaoer) /data/item/w/wulaoer-belt.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jul 15 20:44:02 2002
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m����[2;37;0m", ({ "belt" }));
	set_weight(960);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ��������
[1;37m��[2;37;0m��[1;32m����[2;37;0m��[1;37m�û����ɵ�һ��������������Լɢ���ŵ����Ĺ�â��[2;37;0m
����Ե�Ͽ���һ��С�֣����϶�(wulaoer)
");
	set("value", 2000000);
	set("point", 100);
	set("material", "stone");
	set("wear_msg", "[1;37m$N�ӱ���������ѽ�������һ��[2;37;0m��[1;32m��[2;37;0m��[1;37m���������̹⻯��һ��������[2;37;0m\n");
	set("remove_msg", "[1;32m��������֮��Դ��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
