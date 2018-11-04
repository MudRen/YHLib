// ITEM Made by player(����:luoshen) /data/item/l/luoshen-hand.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue May 14 11:40:35 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m����[1;31m����[1;36m��[2;37;0m", ({ "hand" }));
	set_weight(1530);
	set("item_make", 1);
	set("unit", "˫");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ˫���ơ�
[1;37m����������ʦ�ɽ���ȡ[1;36m��[1;31m��[1;36m��[1;37m[1;37m���񣬼��죬�أ�������֮������[1;31m��ζ���[1;37m���Ͷ��ɵġ�
[1;37m����[1;31m����[1;36m��[2;37;0m[1;37m����һ�㵭���������������ʣ���Ө��͸��[2;37;0m
����Ե�Ͽ���һ��С�֣�����(luoshen)
");
	set("value", 2000000);
	set("point", 126);
	set("material", "stone");
	set("wear_msg", "[37m$N����һЦ��˫�ֻ��������ͻȻ����ǰһ����$N�����Ѿ�����һ˫$n[37m����Ө��͸�����������[2;37;0m\n");
	set("remove_msg", "[37m$N˫�ֹ�£����$n[37m��������֮�У����ֶ������������ݡ�[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/hand", 10);
	set("armor_prop/strike", 10);

	setup();
}

string long() { return query("long") + item_long(); }
