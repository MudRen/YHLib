// ITEM Made by player(������:hatch) /data/item/h/hatch-shi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Jun 14 23:11:49 2002
#include <ansi.h>
#include <weapon.h>

inherit WHIP;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[37m��ǧ����˿[2;37;0m", ({ "shi" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ���ޡ�
�ޱ��Ͽ���һ��С�֣�������(hatch)
");
	set("value", 2000000);
	set("point", 135);
	set("material", "stone");
	set("wield_msg", "[1;37mֻ��������ǰһ����һ������ɫ�ĳ����Գ�����������[2;37;0m\n");
	set("unwield_msg", "[1;37m�׹����������Բ�����[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_whip(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
