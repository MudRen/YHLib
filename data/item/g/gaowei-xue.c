// ITEM Made by player(��Ӱ�:gaowei) /data/item/g/gaowei-xue.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Sep  5 13:56:03 2002
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m����ѥ[2;37;0m", ({ "xue" }));
	set_weight(720);
	set("item_make", 1);
	set("unit", "˫");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ˫ѥ�ӡ�
[1;35m��������ı�֮һ�����������֮�����������ɡ�[2;37;0m
ѥ��Ե�Ͽ���һ��С�֣���Ӱ�(gaowei)
");
	set("value", 2000000);
	set("point", 50);
	set("material", "stone");
	set("wear_msg", "[1;32m$N��Ȼ��һ������𣬵����ɢȥ��ʱ�������϶���һ����׾�ĳ�ѥ[2;37;0m\n");
	set("remove_msg", "[1;36mһʱ��â��ʢ������ɢȥ$N���³�ѥ�Ѿ���ʧ�����ˡ�[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
