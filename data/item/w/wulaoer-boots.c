// ITEM Made by player(���϶�:wulaoer) /data/item/w/wulaoer-boots.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jul 15 20:45:42 2002
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m����[2;37;0m", ({ "boots" }));
	set_weight(720);
	set("item_make", 1);
	set("unit", "˫");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ˫ѥ�ӡ�
[1;37m��[2;37;0m��[1;33m����[2;37;0m��[1;37m�û����ɵ�һ˫սѥ��������Լɢ���ŵ����Ĺ�â��[2;37;0m
ѥ��Ե�Ͽ���һ��С�֣����϶�(wulaoer)
");
	set("value", 2000000);
	set("point", 100);
	set("material", "stone");
	set("wear_msg", "[1;37m$N�ӱ����������ѽ�������һ��[2;37;0m��[1;33m��[2;37;0m��[1;37m���������̹⻯��һ˫սѥ��[2;37;0m\n");
	set("remove_msg", "[1;33m�������͵�������[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
