// ITEM Made by player(����:luoshen) /data/item/l/luoshen-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon May 27 12:50:56 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m����[1;36m��ڤ[1;37m��[2;37;0m", ({ "sword" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ������
[37m����һ����[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m[37mΪԭ�ϣ�����������ԩ�꣬ȡ��ڤ֮�����ơ������������磬������
������������·������ԩ������������צ��Ҫ����ϲϯ���ȥһ�����㲻������һ����ս��[2;37;0m
�����Ͽ���һ��С�֣�����(luoshen)
");
	set("value", 2000000);
	set("point", 136);
	set("material", "stone");
	set("wield_msg", "[1;37mֻ��$Nһ����ߣ�$n[1;37m��Ȼ���ʣ���ʱһ�ɺ���ֱ�����㣬͸��\n�θ�������������������أ���ɳ��ʯ��ֱ�����˹���ʹ�㲻��������[2;37;0m\n");
	set("unwield_msg", "[1;37m$N�������ʣ�һ���Ļ��������ʣ��㲻�����˲�ͷ�ϵĺ�������һ������[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
