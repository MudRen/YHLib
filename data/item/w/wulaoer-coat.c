// ITEM Made by player(���϶�:wulaoer) /data/item/w/wulaoer-coat.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jul 15 18:46:37 2002
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m��ħ[2;37;0m", ({ "coat" }));
	set_weight(2400);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ��ս�¡�
[1;37m��[2;37;0m��[1;37m��ħ[2;37;0m��[1;37m�û����ɵ�һ��ս�£�������Լɢ���ŵ����Ĺ�â��[2;37;0m
ս��Ե�Ͽ���һ��С�֣����϶�(wulaoer)
");
	set("value", 2000000);
	set("point", 250);
	set("material", "stone");
	set("wear_msg", "[1;37m$N�ӱ������ڶ��ѽ�������һ��[2;37;0m��[1;37m��[2;37;0m��[1;37m���������̹⻯��һ��ս�¡�[2;37;0m\n");
	set("remove_msg", "[1;37m�����޾����ǻۡ�[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
