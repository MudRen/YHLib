// ITEM Made by player(����:mong) /data/item/m/mong-yaodai.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Sep 24 07:18:18 2002
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m����[2;37;0m", ({ "yaodai" }));
	set_weight(960);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ��������
����һ������ɫ[1;36m����[2;37;0m������ı������ҫ�۵Ĺ������Ǵ�˵�е�������[1;36m����[2;37;0m��[2;37;0m
����Ե�Ͽ���һ��С�֣�����(mong)
");
	set("value", 2000000);
	set("point", 66);
	set("material", "stone");
	set("wear_msg", "$N����һЦ��ϵ��[1;36m����[2;37;0m��[2;37;0m\n");
	set("remove_msg", "$N����һЦ������[1;36m����[2;37;0m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
