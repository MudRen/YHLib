// ITEM Made by player(����:lhl) /data/item/l/lhl-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed May 29 21:41:45 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m������[2;37;0m", ({ "sword" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ������
[1;33m���[1;37m������[1;33m��ʤ��ԯȴ��Ϊ��֪���˻Ƶ�Ϊ������������������
��������������ĳ�������������[2;37;0m
�����Ͽ���һ��С�֣�����(lhl)
");
	set("value", 2000000);
	set("point", 119);
	set("material", "stone");
	set("wield_msg", "[1;37m������[1;33m���������$N���У�����֮����֮�쳹��أ����ܽ�����ɡ�\n����ֻ�����б����ڲ�ס�����°ڶ��������ڶ����[1;35m���[1;33mߵ������[2;37;0m\n");
	set("unwield_msg", "[1;34m$N�ָ�����������̾��[1;37m������[1;34m�ַ������ڿն�ȥ������֮�����ˣ�����������˿�����[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
