// ITEM Made by player(�γ���:dcai) /data/item/d/dcai-finger.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Oct 23 03:25:18 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0mָ��[2;37;0m", ({ "finger" }));
	set_weight(1190);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ��ָ�ס�
[2;37;0m�������������������ָ�ף�ǰ�˷������У��ȿɰ����������ˣ��ֿɱ���ָ�ؽڡ�[2;37;0m
ָ��Ե�Ͽ���һ��С�֣��γ���(dcai)
");
	set("value", 2000000);
	set("point", 137);
	set("material", "stone");
	set("wear_msg", "[33m$N����һ��ָ��[2;37;0m\n");
	set("remove_msg", "[33m$Nж��ָ�׵�װ����[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/finger", 10);
	set("armor_prop/claw", 10);
	set("armor_prop/armor", 10);

	setup();
}

string long() { return query("long") + item_long(); }
