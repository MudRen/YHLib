// ITEM Made by player(Ľ�ݼͷ�:gtjf) /data/item/g/gtjf-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Jul 18 11:08:10 2002
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("����[2;37;0m", ({ "sword" }));
	set_weight(6750);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[37m����[2;37;0m���ƶ��ɵ�һ�ѵ���
�����Ͽ���һ��С�֣�Ľ�ݼͷ�(gtjf)
");
	set("value", 800000);
	set("point", 30);
	set("material", "iron");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
