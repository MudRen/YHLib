// ITEM Made by player(Ľ��а��:xieshen) /data/item/x/xieshen-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Jan 21 08:45:15 2003
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m�Ļ꽣[2;37;0m", ({ "sword" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ������
�����Ͽ���һ��С�֣�Ľ��а��(xieshen)
");
	set("value", 2000000);
	set("point", 144);
	set("material", "stone");
set("wield_msg", HIW "$NĬ��̫���������������������������پ�ȫ���Ȼ�������᲻�ɴݡ�\n" NOR);
            set("unwield_msg", HIG "$NĬĬ�˹����������͵�ʯ���ϵĿھ�һһ���֣�̫�����ھ��ѻ���ȫ��\n" NOR);
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
