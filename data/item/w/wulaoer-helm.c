// ITEM Made by player(���϶�:wulaoer) /data/item/w/wulaoer-helm.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jul 15 18:44:13 2002
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;35m����[2;37;0m", ({ "helm" }));
	set_weight(2550);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ��ͷ����
[1;37m��[2;37;0m��[1;35m����[2;37;0m��[1;37m�û����ɵ�һ��ͷ����������Լɢ���ŵ����Ĺ�â��[2;37;0m
ͷ��Ե�Ͽ���һ��С�֣����϶�(wulaoer)
");
	set("value", 2000000);
	set("point", 150);
	set("material", "stone");
	set("wear_msg", "[1;37m$N�ӱ�������һ�ѽ�������һ��[2;37;0m��[1;35m��[2;37;0m��[1;37m���������̹⻯��һ��ͷ����[2;37;0m\n");
	set("remove_msg", "[1;35m���ǲ���Ĺ�ԡ�[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
