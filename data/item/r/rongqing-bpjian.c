// ITEM Made by player(��������:rongqing) /data/item/r/rongqing-bpjian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Jun 28 22:22:03 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m���Ǻ��⽣[2;37;0m", ({ "bpjian" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ������
[1;33m�������������ۣ���Ѫ���������档˭�����е����裬������������١�[2;37;0m
�����Ͽ���һ��С�֣���������(rongqing)
");
	set("value", 2000000);
	set("point", 135);
	set("material", "stone");
	set("wield_msg", "[1;36m���ϡ���һ��������$N���о���һ�����ߺ�����ϸ��֮�£���Ȼ�������������ġ����Ǻ��⽣����[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
