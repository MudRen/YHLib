// ITEM Made by player(�γ���:dcai) /data/item/d/dcai-xizhang.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Sep 27 21:40:53 2002
#include <ansi.h>
#include <weapon.h>

inherit STAFF;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m�Ż�����[2;37;0m", ({ "xizhang" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ���ȡ�
[1;37m����һ��ͨ����ڵ����ȣ����ּ�Ϊ���أ��ǳ����ͣ��������������ഫ��ʥ����ƣ�ͭ��������������Ž�������פ�ա�[2;37;0m
�ȱ��Ͽ���һ��С�֣��γ���(dcai)
");
	set("value", 2000000);
	set("point", 126);
	set("material", "stone");
	set("wield_msg", "[1;37m$Nȡ���Ż������������У���ʱ�𲨵����������߷�����[2;37;0m\n");
	set("unwield_msg", "[1;37m$N΢΢һЦ�������еľŻ����ȷŻذ��ҡ�[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_staff(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
