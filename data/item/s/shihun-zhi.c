// ITEM Made by player(ʧ����:shihun) /data/item/s/shihun-zhi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jul  3 20:08:06 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[37mָ��[2;37;0m", ({ "zhi" }));
	set_weight(1190);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ��ָ�ס�
[36mһ���������۵�[2;37;0m[37mָ��[2;37;0m[36m��[2;37;0m
ָ��Ե�Ͽ���һ��С�֣�ʧ����(shihun)
");
	set("value", 2000000);
	set("point", 138);
	set("material", "stone");
	set("wear_msg", "$n[36m����ţ���������ô����[2;37;0m\n");
	set("remove_msg", "$n[36m�����᲻����ѽ�����ǣ���������������������[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/finger", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/claw", 10);
	set("armor_prop/unarmed_damage", apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
