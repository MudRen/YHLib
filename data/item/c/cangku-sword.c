// ITEM Made by player(С����:cangku) /data/item/c/cangku-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Jan 14 13:39:07 2003
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[34mĩ�յ�����[2;37;0m", ({ "sword" }));
	set_weight(6750);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[37m����[2;37;0m���ƶ��ɵ�һ������
[1;33m����ȥֻ�о���ǰ���ң�����ģ����[2;37;0m
�����Ͽ���һ��С�֣�С����(cangku)
");
	set("value", 800000);
	set("point", 30);
	set("material", "iron");
	set("wield_msg", "[1;31m$NĿ���罣��һ����ׯ�ϳ��ȵ�������������ɲ�Ǽ���ر�ɫ������������\n[1;33m��ĩ�յ�����ʱ���ҽ��Լ����ҵĵ��������������ƽ�ϣ�����Զ������Ĳþ���\n[1;32m������ˣ������꽫�õ����յĿ�ˡ��[2;37;0m\n");
	set("unwield_msg", "[34mа����ˣ���Ľ��ܵ����յ����С�\n[1;31m���彫�ڻ���������л��������꽫�ڳ���֮���������յ�ʹ�����į��\n[35m����������ᣬ��ǰ��һ�У�������ʼ�仯���������Ҳ����ģ������[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
