// ITEM Made by player(���϶�:wulaoer) /data/item/w/wulaoer-jian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Jul 11 03:18:46 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m����[1;36mʮ����[2;37;0m", ({ "jian" }));
	set_weight(10000);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[36m��ɽ����[2;37;0m���ƶ��ɵ�һ������
[1;37m���������ߴ磬�������ƺ��������������С�֣�������һ����ȴʲôҲ�����塣[2;37;0m
�����Ͽ���һ��С�֣����϶�(wulaoer)
");
	set("value", 3000000);
	set("point", 370);
	set("material", "stone");
	set("wield_msg", "[1;37mһ���˲����У����޺��ձ��������޽��˲�Ϣ��\n�ĺ���̬�����������̨��©��������Ҷ�ཹ��[2;37;0m\n");
	set("unwield_msg", "[1;37m�ߺ޺����������˺޼ܻ����̣��ź���ҹ���á�\nʮ��Ѧ�ܲ�򳣬ʮһ��δ���ܹ���ʮ���������޵С�[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
