// ITEM Made by player(���:sunjun) /data/item/s/sunjun-zhi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Aug 10 15:17:38 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m���ָ[2;37;0m", ({ "zhi" }));
	set_weight(1190);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ��ָ�ס�
ָ��Ե�Ͽ���һ��С�֣����(sunjun)
");
	set("value", 2000000);
	set("point", 144);
	set("material", "stone");
	set("wear_msg", "[33m$N[33mװ��[1;33m���ָ[2;37;0m[33m��[2;37;0m\n");
	set("remove_msg", "[33m$N[33m������[1;33m���ָ[2;37;0m[33m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/claw", 10);
	set("armor_prop/finger", 10);
	set("armor_prop/unarmed_damage", apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
