// ITEM Made by player(����Ȼ:jiao) /data/item/j/jiao-zhi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Mar 27 20:13:31 2003
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m����ն[2;37;0m", ({ "zhi" }));
	set_weight(1190);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ��ָ�ס�
[1;31m����Ȼ΢һ������������񹦣������������ڵ���֮�У����澭�����鲼ȫ��[2;37;0m
ָ��Ե�Ͽ���һ��С�֣�����Ȼ(jiao)
");
	set("value", 2000000);
	set("point", 171);
	set("material", "stone");
	set("wear_msg", "[1;31m$NĬ������񹦵Ŀھ�����ǿ����ǿ������ɽ�ԡ����������ᣬ�����մ󽭡���[2;37;0m\n");
	set("remove_msg", "[1;31mɲ�Ǽ�ֻ����ȫ���ʱ���ֳ�һ����͵ľ���������ȫȫ���֡�[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/finger", 10);
	set("armor_prop/claw", 10);
	set("armor_prop/armor", 10);

	setup();
}

string long() { return query("long") + item_long(); }
