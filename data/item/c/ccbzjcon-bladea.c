// ITEM Made by player(�����۳:ccbzjcon) /data/item/c/ccbzjcon-bladea.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun May 05 12:11:17 2002
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[30mħ��[2;37;0m", ({ "bladea" }));
	set_weight(6750);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m�׻𺮾�[2;37;0m���ƶ��ɵ�һ�ѵ���
�����Ͽ���һ��С�֣������۳(ccbzjcon)
");
	set("value", 1600000);
	set("point", 91);
	set("material", "stone");
	set("wield_msg", "$N���һ��[1;33mħ��[30mħ��[2;37;0m�������С�[2;37;0m\n");
	set("unwield_msg", "$N�������е�[1;33mħ��[30mħ��[2;37;0m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
