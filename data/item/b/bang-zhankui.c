// ITEM Made by player(����:bang) /data/item/b/bang-zhankui.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Oct 14 00:07:27 2002
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m�컨ս��[2;37;0m", ({ "zhankui" }));
	set_weight(2550);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ��ͷ����
ͷ��Ե�Ͽ���һ��С�֣�����(bang)
");
	set("value", 2000000);
	set("point", 75);
	set("material", "stone");
	set("wear_msg", "[33m$N[33mװ��[1;33m�컨ս��[2;37;0m[33m��[2;37;0m\n");
	set("remove_msg", "[33m$N[33m������[1;33m�컨ս��[2;37;0m[33m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
