// ITEM Made by player(����:dudu) /data/item/d/dudu-whip.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Sep 16 16:38:49 2002
#include <ansi.h>
#include <weapon.h>

inherit WHIP;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[30m����[2;37;0m", ({ "whip" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ���ޡ�
[30m����һ����ڵĳ��ޣ��������ۣ��������ֳ��أ��Ҳ�ʧ���ͣ�ʵ����ǧ������֮�[2;37;0m
�ޱ��Ͽ���һ��С�֣�����(dudu)
");
	set("value", 2000000);
	set("point", 139);
	set("material", "stone");
	set("wield_msg", "[30m$Nһ���֣�������Ϣ�Ľ������������С�[2;37;0m\n");
	set("unwield_msg", "[30m$N�����еĺ������𣬷Ż����䡣[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_whip(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
