// ITEM Made by player(���:sunjun) /data/item/s/sunjun-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Jun 09 09:04:23 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m��[1;32mħ[1;34m��[2;37;0m", ({ "sword" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ������
[1;36m����һ�Ѻ���������ͨ�徧Ө���ǽ����������һ�κ����ı������������˼��һ��������˫���챦���䡣[2;37;0m
�����Ͽ���һ��С�֣����(sunjun)
");
	set("value", 2000000);
	set("point", 125);
	set("material", "stone");
	set("wield_msg", "[1;32mֻ��[1;35m$N[1;32m����һЦ���ӻ���ȡ��һ�ѱ�����[1;31m��[1;37mħ[1;34m��[1;32m��һ�Ӷ����������⣬���������淢�䡣[2;37;0m\n");
	set("unwield_msg", "[1;31m��[1;32mħ[1;34m��[1;37m��[1;35m$N[1;37m����һת��գ�ۼ��Ѳ�����Ӱ��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
