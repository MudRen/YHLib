// ITEM Made by player(����:miaomiao) /data/item/m/miaomiao-laodao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jul 15 20:23:44 2002
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[36m��߶[2;37;0m", ({ "laodao" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ�ѵ���
[30m���ǵ������ֵ�һ���˳����ñ�����Ѫ֮�����ˡ��ˣ���ѽ�������ˣ�[2;37;0m
�����Ͽ���һ��С�֣�����(miaomiao)
");
	set("value", 2000000);
	set("point", 173);
	set("material", "stone");
	set("wield_msg", "[1;37mֻ��$N���������дʣ���[36m$n[1;37m߶����Χ���˶�ʱͷʹ���ѡ�[2;37;0m\n");
	set("unwield_msg", "$Nֹͣ��$n����Χ��ʱ������������[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
