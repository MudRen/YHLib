// ITEM Made by player(����:mong) /data/item/m/mong-xie.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Sep  5 09:25:00 2002
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36mѥ��[2;37;0m", ({ "xie" }));
	set_weight(720);
	set("item_make", 1);
	set("unit", "˫");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ˫ѥ�ӡ�
����һ������ɫѥ�ӣ��������ҫ�۵Ĺ������Ǵ�˵�е�������[1;36mѥ��[2;37;0m��[2;37;0m
ѥ��Ե�Ͽ���һ��С�֣�����(mong)
");
	set("value", 2000000);
	set("point", 65);
	set("material", "stone");
	set("wear_msg", "$N�ɿ�Ĵ���[1;36mѥ��[2;37;0m����ס�����ϵ��ƶ���[2;37;0m\n");
	set("remove_msg", "$N�ɿ������[1;36mѥ��[2;37;0m��¶���������ϵ��ƶ���[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
