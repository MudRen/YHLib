// ITEM Made by player(����:lilac) /data/item/l/lilac-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Jun 11 12:41:35 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[34m����[35m�ļ�[1;32m��[2;37;0m", ({ "sword" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ������
[1;36m�ҵİ��ˡ�������
[1;36m�������
[1;36m������������
[1;36m���ҹ⻬����������
[1;36m���ò������֡�������
[1;36m��������еķ���[2;37;0m
�����Ͽ���һ��С�֣�����(lilac)
");
	set("value", 2000000);
	set("point", 121);
	set("material", "stone");
	set("wield_msg", "[35m������ʫ\n[35m����Ҳ���޷ɻ�����ϸ��\n[35m������ļ���\n[35m������[2;37;0m\n");
	set("unwield_msg", "[34m��㡡��������\n[34m���������Ϩ\n[34m�ػ��˼�\n[34m��Ȼ�Ѿ���ǧ������������\n[34m��֪��·������Ȼ�Ĺ켣[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
