// ITEM Made by player(����:yanrong) /data/item/y/yanrong-clothd.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Jun 02 19:54:41 2002
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m��[1;37mң[1;32m��[2;37;0m", ({ "clothd" }));
	set_weight(2400);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ��ս�¡�
ս��Ե�Ͽ���һ��С�֣�����(yanrong)
");
	set("value", 2000000);
	set("point", 135);
	set("material", "stone");
	set("wear_msg", "$N����һ��[1;36m��[1;37mң[1;32m��[2;37;0m��[2;37;0m\n");
	set("remove_msg", "$N��[1;36m��[1;37mң[1;32m��[2;37;0m����������[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
