// ITEM Made by player(С��:abc) /data/item/a/abc-jiezhi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu May 09 22:02:12 2002
#include <ansi.h>
#include <weapon.h>

inherit XSWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("����ָ[2;37;0m", ({ "jiezhi" }));
	set_weight(1350);
	set("item_make", 1);
	set("unit", "֧");
	set("long", "������[2;37;0m[1;31m�׻𺮾�[2;37;0m���ƶ��ɵ�һ֧�
����С���͸�����Ķ������[2;37;0m
����Ͽ���һ��С�֣�С��(abc)
");
	set("value", 1600000);
	set("point", 97);
	set("material", "stone");
	set("wield_msg", "���������һö����ָ��[2;37;0m\n");
	set("unwield_msg", "���������һö����ָ��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_xsword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
