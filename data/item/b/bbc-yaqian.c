// ITEM Made by player(�㲥��̨:bbc) /data/item/b/bbc-yaqian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Mar 15 20:19:47 2003
#include <ansi.h>
#include <weapon.h>

inherit STAFF;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m��ǩ[2;37;0m", ({ "yaqian" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[33m�ѽ���[2;37;0m���ƶ��ɵ�һ���ȡ�
�ȱ��Ͽ���һ��С�֣��㲥��̨(bbc)
");
	set("value", 1200000);
	set("point", 50);
	set("material", "stone");
	set("wield_msg", "�ԣ���֪��������ɳ���һ����ǩ��[2;37;0m\n");
	set("unwield_msg", "$N����һĨ��������$n��\n");
	if (! check_clone()) return;
	restore();
	init_staff(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
