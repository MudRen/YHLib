// ITEM Made by player(С�ֹ�һ:xlgy) /data/item/x/xlgy-zhuxiao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri May 24 17:39:32 2002
#include <ansi.h>
#include <weapon.h>

inherit XSWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("����[2;37;0m", ({ "zhuxiao" }));
	set_weight(1350);
	set("item_make", 1);
	set("unit", "֧");
	set("long", "������[37m����[2;37;0m���ƶ��ɵ�һ֧�
����Ͽ���һ��С�֣�С�ֹ�һ(xlgy)
");
	set("value", 800000);
	set("point", 30);
	set("material", "iron");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ֧[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_xsword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
