// ITEM Made by player(����:dagou) /data/item/d/dagou-dagou.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Jun 25 17:52:25 2002
#include <ansi.h>
#include <weapon.h>

inherit STAFF;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m��[1;31m��[1;37m��[2;37;0m", ({ "dagou" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ���ȡ�
�ȱ��Ͽ���һ��С�֣�����(dagou)
");
	set("value", 2000000);
	set("point", 180);
	set("material", "stone");
	set("wield_msg", "[1;36m$N[1;36mһ����Х������һ��[1;36m$n[1;36m��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_staff(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
