// ITEM Made by player(���齣ħ:fbm) /data/item/f/fbm-bjian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Aug 28 13:04:40 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m����[31mħ[34m��[2;37;0m", ({ "bjian" }));
	set_weight(30000);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[36m��ɽ����[2;37;0m���ƶ��ɵ�һ������
[1;34m����һ�Ѵ���ɽͯ����������͵����а����һ�������кô��[31m��[1;34m����[2;37;0m
�����Ͽ���һ��С�֣����齣ħ(fbm)
");
	set("value", 2200000);
	set("point", 130);
	set("material", "stone");
	set("wield_msg", "[1;34m����ͻȻһ����������ǰ���ȡ�������ѽ�����������ˡ�����[31m����������������[2;37;0m\n");
	set("unwield_msg", "[32mͻȻһ������һ��Ѷ������ȡ���������[31m����[32mȫû�ˡ�����[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
