// ITEM Made by player(ħ������:iliilil) /data/item/i/iliilil-whip.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Oct 18 15:01:12 2002
#include <ansi.h>
#include <weapon.h>

inherit WHIP;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m�����[2;37;0m", ({ "whip" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ���ޡ�
[1;31m����Ϲ�������ǵ���[1;35m�����������ʧ����[1;33m����ޡ�[2;37;0m
�ޱ��Ͽ���һ��С�֣�ħ������(iliilil)
");
	set("value", 2000000);
	set("point", 130);
	set("material", "stone");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_whip(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
