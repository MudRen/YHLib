// ITEM Made by player(л����:china) /data/item/c/china-xiao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Oct 13 14:01:17 2002
#include <ansi.h>
#include <weapon.h>

inherit XSWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m�����鳤��[2;37;0m", ({ "xiao" }));
	set_weight(1020);
	set("item_make", 1);
	set("unit", "֧");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ֧�
[1;36m����һƷ��ɫ���������ݴ����ǡ����µ�һ��ա�л���崵������鳤������������Գ����Ů���������ԡ�
[2;37;0m
����Ͽ���һ��С�֣�л����(china)
");
	set("value", 2000000);
	set("point", 133);
	set("material", "stone");
	set("wield_msg", "[1;36m$N��ִ�����鳤�ﳤ����\nһ�ж����ᣬ�޳��ѵþ�\n������η�壬��Σ춳�¶\n�ɰ������ǣ��ɰ�������\n����춰��ߣ��������޲�\n[2;37;0m\n");
	set("unwield_msg", "[1;36mһ�����գ��㳤̾��\n��������Ϊ���ֱ����������\n[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_xsword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
