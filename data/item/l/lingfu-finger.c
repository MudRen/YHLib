// ITEM Made by player(�鸣:lingfu) /data/item/l/lingfu-finger.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Aug 22 22:04:27 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("ָ��[2;37;0m", ({ "finger" }));
	set_weight(1190);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ��ָ�ס�
ָ��Ե�Ͽ���һ��С�֣��鸣(lingfu)
");
	set("value", 2000000);
	set("point", 156);
	set("material", "stone");
	set("wear_msg", "$N����һ��ָ�ס�[2;37;0m\n");
	set("remove_msg", "$Nж��ָ�׵�װ����[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/finger", 10);
	set("armor_prop/claw", 10);

	setup();
}

string long() { return query("long") + item_long(); }
