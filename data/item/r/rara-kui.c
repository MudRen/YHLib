// ITEM Made by player(�̼�:rara) /data/item/r/rara-kui.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Mar 24 12:01:11 2003
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33mͷ��[2;37;0m", ({ "kui" }));
	set_weight(2550);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ��ͷ����
ͷ��Ե�Ͽ���һ��С�֣��̼�(rara)
");
	set("value", 2000000);
	set("point", 89);
	set("material", "stone");
	set("wear_msg", "[33m$N[33mװ��[1;33mͷ��[2;37;0m[33m��[2;37;0m\n");
	set("remove_msg", "[33m$N[33m������[1;33mͷ��[2;37;0m[33m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
