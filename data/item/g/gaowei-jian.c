// ITEM Made by player(��Ӱ�:gaowei) /data/item/g/gaowei-jian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Sep 14 18:05:11 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m�԰׵�����[2;37;0m", ({ "jian" }));
	set_weight(15000);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m����쾧[2;37;0m���ƶ��ɵ�һ������
[1;32m���ǲ�����֮������������Ʃ�ӵ�����֮���������׾���ţ��������������������ķ��š��ڰ����Ľ����ϣ���������һ�����֡�[1;37m���ȼ������ܱ������[2;37;0m
�����Ͽ���һ��С�֣���Ӱ�(gaowei)
");
	set("value", 4200000);
	set("point", 554);
	set("material", "tian jing");
	set("wield_msg", "[1;31m$Nһȭ�����أ�ׯ�϶����ȵ�������������\n[1;32m�ٻ������Ѫ���е�Զ��ʥ����\n[1;32mʧ�����֮��ѽ�����ڴ����󴫳С�\n[1;32mΪ���������̵���������Ϊ���ۡ�\n[1;32m˲��ﵽ���ߵĵ߷塭��[2;37;0m\n");
	set("unwield_msg", "[35m$N��̾һ��������֮�������������ʧ������[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
