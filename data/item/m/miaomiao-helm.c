// ITEM Made by player(����:miaomiao) /data/item/m/miaomiao-helm.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Apr  7 17:02:48 2003
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m������[2;37;0m", ({ "helm" }));
	set_weight(2550);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ��ͷ����
[1;33m����߲������۳ɵ�ͷ����[2;37;0m
ͷ��Ե�Ͽ���һ��С�֣�����(miaomiao)
");
	set("value", 2000000);
	set("point", 105);
	set("material", "stone");
	set("wear_msg", "[1;33mֻ���ð��֮������ӯ�գ��廷֮��������ϼ�����������߲���������$Nͷ����[2;37;0m\n");
	set("remove_msg", "[1;33m$N��ָ��ӽ��۶�����������ȥ��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
