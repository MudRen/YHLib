// ITEM Made by player(��Ӱ�:gaowei) /data/item/g/gaowei-bian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Feb 20 21:05:51 2003
#include <ansi.h>
#include <weapon.h>

inherit WHIP;
inherit F_ITEMMAKE;

void create()
{
	set_name("����[2;37;0m", ({ "bian" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[37m����˿[2;37;0m���ƶ��ɵ�һ���ޡ�
�ޱ��Ͽ���һ��С�֣���Ӱ�(gaowei)
");
	set("value", 900000);
	set("point", 35);
	set("material", "silk");
	set("wield_msg", "[1;32m$Nʩչ��ũ���ݾ���������������͸��һ˿��ɫ������\n[1;33m�����³�һ����Ѫ��������ЩЧ����[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_whip(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
