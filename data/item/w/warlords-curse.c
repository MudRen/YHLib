// ITEM Made by player(�������:warlords) /data/item/w/warlords-curse.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Jun 15 13:46:05 2002
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("����֮��[2;37;0m", ({ "curse" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[35m�Ͻ��[2;37;0m���ƶ��ɵ�һ�Ż��ס�
���԰������Ǵ�½�Ĳ���֮���˵�к�ǿ���ħ����[2;37;0m
����Ե�Ͽ���һ��С�֣��������(warlords)
");
	set("value", 1200000);
	set("point", 52);
	set("material", "stone");
	set("wear_msg", "[33m$N[33mװ������֮��[2;37;0m[33m��[2;37;0m\n");
	set("remove_msg", "[33m$N[33m����������֮��[2;37;0m[33m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
