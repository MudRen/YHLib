// ITEM Made by player(����:mong) /data/item/m/mong-xyj.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Oct 12 13:45:20 2002
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m��ң��[2;37;0m", ({ "xyj" }));
	set_weight(2550);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ��ͷ����
����һ������ɫͷ������ı������ҫ�۵Ĺ������Ǵ�˵�е�������[1;36m��ң��[2;37;0m��[2;37;0m
ͷ��Ե�Ͽ���һ��С�֣�����(mong)
");
	set("value", 2000000);
	set("point", 84);
	set("material", "stone");
	set("wear_msg", "$N΢΢һЦ����[1;36m��ң��[2;37;0m��ס���Լ���ͷ����[2;37;0m\n");
	set("remove_msg", "$N����һ̾���⿪��ͷ���ϵ�[1;36m��ң��[2;37;0m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
