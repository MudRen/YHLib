// ITEM Made by player(С��:xiaodai) /data/item/x/xiaodai-jian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Jul 11 03:08:29 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m����[1;37m�Ž�[2;37;0m", ({ "jian" }));
	set_weight(10000);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[36m��ɽ����[2;37;0m���ƶ��ɵ�һ������
�����Ͽ���һ��С�֣�С��(xiaodai)
");
	set("value", 3200000);
	set("point", 500);
	set("material", "stone");
	set("wield_msg", "[1;33m$N���һ���ӱ���������[1;37m�Ž���[1;33m����������â���֣�һ����ɱ֮����Ȼ������[2;37;0m\n");
	set("unwield_msg", "[1;37m$N��[1;33m����[1;37m�Ž������������ڣ�˫�ֻ��ض��������жٸк�����ǧ��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
