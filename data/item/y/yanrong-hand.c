// ITEM Made by player(����:yanrong) /data/item/y/yanrong-hand.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Jun 28 21:38:24 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m��[1;37mң[1;32mָ[2;37;0m", ({ "hand" }));
	set_weight(1190);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ��ָ�ס�
[1;35mɢ���Ź��ӹ�������ָ�������[1;36m��[1;37mң[1;32mָ[2;37;0m��[2;37;0m
ָ��Ե�Ͽ���һ��С�֣�����(yanrong)
");
	set("value", 2000000);
	set("point", 147);
	set("material", "stone");
	set("wear_msg", "$N΢΢һЦ���������һö[1;36m��[1;37mң[1;32mָ[2;37;0m����ʱָ��⻪���䡣[2;37;0m\n");
	set("remove_msg", "$N��[1;36m��[1;37mң[1;32mָ[2;37;0m��ָ��ȡ��������[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/finger", 10);
	set("armor_prop/claw", 10);

	setup();
}

string long() { return query("long") + item_long(); }
