// ITEM Made by player(�����:jiusword) /data/item/j/jiusword-mysword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Oct 10 22:55:13 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m���ν���[2;37;0m", ({ "mysword" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ������
����������һ�㱡���ǽ��ǽ�[2;37;0m
�����Ͽ���һ��С�֣������(jiusword)
");
	set("value", 2000000);
	set("point", 119);
	set("material", "stone");
	set("wield_msg", "[1;31m$N΢һ�������������񹦣������������ڵ���֮�У����澭�����鲼ȫ��[2;37;0m\n");
	set("unwield_msg", "[1;31m$NĬ������񹦵Ŀھ�����ǿ����ǿ������ɽ�ԡ����������ᣬ�����մ󽭡���[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
