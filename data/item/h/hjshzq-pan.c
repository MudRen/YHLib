// ITEM Made by player(���:hjshzq) /data/item/h/hjshzq-pan.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jun 26 15:27:14 2002
#include <ansi.h>
#include <weapon.h>

inherit HAMMER;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m��Ϸ����[2;37;0m", ({ "pan" }));
	set_weight(11900);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ�Ѵ���
[1;32m����һ�������Ͽ���������Ϸ���̣������Ͼ�Ө��͸�������Ϸ���ʯ��������Χ�з����ľ�ݣ�����Ϳ�����飮ʹ�˼��˲���������[2;37;0m
�����Ͽ���һ��С�֣����(hjshzq)
");
	set("value", 2000000);
	set("point", 135);
	set("material", "stone");
	set("wield_msg", "[35mֻ�����ѵ���һ����$N�����Ѷ��һ�ֻ��$NĿ�о������䣬�������ݣ�������������֮�����֮������������ֻ������Ѫ��ӿ��ѹ���ѵ����׷������˹���Ϣ��[2;37;0m\n");
	set("unwield_msg", "[1;32mֻ�������ϡ�һ����$Nһ����̾������Ϸ�����ջ����䣬���˼����������첻����[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_hammer(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
