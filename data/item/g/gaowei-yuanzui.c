// ITEM Made by player(��Ӱ�:gaowei) /data/item/g/gaowei-yuanzui.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Sep 25 03:33:45 2002
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[36mԭ��[2;37;0m", ({ "yuanzui" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ�Ż��ס�
[33m�����Ϲ�����֮һ����֪����ʲô�������������ף�������������������ֺ���[2;37;0m
����Ե�Ͽ���һ��С�֣���Ӱ�(gaowei)
");
	set("value", 2000000);
	set("point", 93);
	set("material", "stone");
	set("wear_msg", "$N�����ٻ����\n[33m��صľ���ѽ�����ƹ������յķ����ͻָ���\n[33m�������������ң�����ʵ�������ߡ�\n[1;34mɲ�Ǽ�⻪������$N���϶���һ����׾�������ס�[2;37;0m\n");
	set("remove_msg", "[33m$N��Ȼ��������У������ٴ������ʱ�����ϵ��������Ѿ���ʧ�����ˡ�[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/parry", apply_armor() / 15 + 1);
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
