// ITEM Made by player(����:xxwy) /data/item/x/xxwy-snow.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue May 21 14:11:19 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m����ѩ[2;37;0m", ({ "snow" }));
	set_weight(1350);
	set("item_make", 1);
	set("unit", "˫");
	set("long", "������[1;32mǬ[1;37m��[1;33mʯ[2;37;0m���ƶ��ɵ�һ˫���ơ�
[1;36m��һ�������Ϊ�̣����������񣬹⻪��ӳ���ݷ�������������ѩ��[2;37;0m
����Ե�Ͽ���һ��С�֣�����(xxwy)
");
	set("value", 2200000);
	set("point", 133);
	set("material", "stone");
	set("wear_msg", "$Nһ����Х��[1;36m����ѩ[2;37;0m��$N��Ϊһ�塣[2;37;0m\n");
	set("remove_msg", "$N��̾һ����[1;36m����ѩ[2;37;0m��$N�������˿�����[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/hand", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/strike", 10);
	set("armor_prop/armor", 10);

	setup();
}

string long() { return query("long") + item_long(); }
