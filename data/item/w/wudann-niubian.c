// ITEM Made by player(Ľ������:wudann) /data/item/w/wudann-niubian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Feb  7 09:42:35 2003
#include <ansi.h>
#include <weapon.h>

inherit WHIP;
inherit F_ITEMMAKE;

void create()
{
	set_name("ţ��[2;37;0m", ({ "niubian" }));
	set_weight(6750);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[37m����[2;37;0m���ƶ��ɵ�һ���ޡ�
�ޱ��Ͽ���һ��С�֣�Ľ������(wudann)
");
	set("value", 800000);
	set("point", 30);
	set("material", "iron");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_whip(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
