// ITEM Made by player(��ӧ:hongying) /data/item/h/hongying-zhuozhou.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Dec 19 09:37:36 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m����[2;37;0m", ({ "zhuozhou" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ������
[1;31m��ѽ������ߣ���������һ�ְ���ɫ�Ĺ�â����˵ֻҪ���˰����ƽ⣬���ܳ�Ϊ�������ʮ�أ�ʮ��ħ��֮����[2;37;0m
�����Ͽ���һ��С�֣���ӧ(hongying)
");
	set("value", 2000000);
	set("point", 142);
	set("material", "stone");
	set("wield_msg", "[1;33mһȭ�����أ�ɲʱ�����������ؼ�һƬ�Ұ���һ��Ѫɫ�����������Ӵ���ѿ�б��������[2;37;0m\n");
     set("unwield_msg", HIY"���г����ڿ�������������ʧ����Ӱ���١�\n"NOR);
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
