// ITEM Made by player(����:miaomiao) /data/item/m/miaomiao-baojia.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu May 09 02:29:48 2002
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m��˿[1;33m����[2;37;0m", ({ "baojia" }));
	set_weight(2400);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ��ս�¡�
һ��������ļף��������ۡ�[2;37;0m
ս��Ե�Ͽ���һ��С�֣�����(miaomiao)
");
	set("value", 2000000);
	set("point", 186);
	set("material", "stone");
	set("wear_msg", "[1;33m$N����һ��[1;36m��˿[1;33m���ס�[2;37;0m\n");
	set("remove_msg", "[1;33m$N��[1;36m��˿[1;33m��������������[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
