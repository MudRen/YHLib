// ITEM Made by player(������:tianjian) /data/item/t/tianjian-jian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Nov  5 13:30:27 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[35mѪ�ϵĲþ�[2;37;0m", ({ "jian" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ������
[1;31m��ѽ����ĳߣ�������ǳǳ��Ѫ�ƣ�������ת�������������ֳ��Źֵ�ͼ�������Ͻ�Ľ������õ����˼���Ѫɫ���֣�
[35m��������ħ��Ѫɫ�����ޡ�[2;37;0m
�����Ͽ���һ��С�֣�������(tianjian)
");
	set("value", 2000000);
	set("point", 129);
	set("material", "stone");
	set("wield_msg", "[1;31m$N����ͻȻ���������Ĺ⻪�������������������\n[35m�ٻ������Ѫ���е�Զ��ʥ����\n[35mʧ���Ѫɫ֮���������ڴ����󴫳С�\n[35m���ҵ���������������˲��Ϊ���ۡ�\n[1;31mһ����ɫ�ĳ���ƾ�ճ�����$N���С�[2;37;0m\n");
	set("unwield_msg", "[1;35m�⻪��ȥ��$N���е���ɫ������ƾ����ʧ���������������һ�㡣[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
