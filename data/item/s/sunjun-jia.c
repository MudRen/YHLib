// ITEM Made by player(���:sunjun) /data/item/s/sunjun-jia.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Aug 10 13:51:23 2002
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m��ٱ���[2;37;0m", ({ "jia" }));
	set_weight(2400);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ��ս�¡�
ս��Ե�Ͽ���һ��С�֣����(sunjun)
");
	set("value", 2000000);
	set("point", 144);
	set("material", "stone");
	set("wear_msg", "[33m$N[33mװ��[1;32m��ٱ���[2;37;0m[33m��[2;37;0m\n");
	set("remove_msg", "[33m$N[33m������[1;32m��ٱ���[2;37;0m[33m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
