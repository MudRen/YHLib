// ITEM Made by player(��Ӱ�:gaowei) /data/item/g/gaowei-jia.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Sep  5 14:03:04 2002
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m�ü�[2;37;0m", ({ "jia" }));
	set_weight(2400);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ��ս�¡�
[35m��������ı�֮һ�����������֮�����������ɡ�[2;37;0m
ս��Ե�Ͽ���һ��С�֣���Ӱ�(gaowei)
");
	set("value", 2000000);
	set("point", 126);
	set("material", "stone");
	set("wear_msg", "[1;33m$N��Ȼ��һ������𣬵����ɢȥ��ʱ�������϶���һ�������ƻõĳ�����[2;37;0m\n");
	set("remove_msg", "[37mһʱ��â��ʢ������ɢȥ$N���ϵĳ����Ѿ���ʧ�����ˡ�[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
