// ITEM Made by player(���:sunjun) /data/item/s/sunjun-guan.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Jul 26 13:11:38 2002
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m��[1;35m��[2;37;0m", ({ "guan" }));
	set_weight(2550);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ��ͷ����
[1;36m���˵���ʺ����͵ķ�ڣ��ǻʹ���һ���[2;37;0m
ͷ��Ե�Ͽ���һ��С�֣����(sunjun)
");
	set("value", 2000000);
	set("point", 72);
	set("material", "stone");
	set("wear_msg", "[33m$N[33mװ��[1;31m��[1;35m��[2;37;0m[33m��[2;37;0m\n");
	set("remove_msg", "[33m$N[33m������[1;31m��[1;35m��[2;37;0m[33m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
