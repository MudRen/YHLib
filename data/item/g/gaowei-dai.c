// ITEM Made by player(��Ӱ�:gaowei) /data/item/g/gaowei-dai.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Sep 25 02:41:26 2002
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m����̫��[2;37;0m", ({ "dai" }));
	set_weight(960);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ��������
[1;33m�����Ϲ�����֮һ����˸�������Ϲ����������֪�ɺ�����֯����������������[2;37;0m
����Ե�Ͽ���һ��С�֣���Ӱ�(gaowei)
");
	set("value", 2000000);
	set("point", 46);
	set("material", "stone");
	set("wear_msg", "[1;31m$N΢һ������������񹦣������������ڵ���֮�У����澭�����鲼ȫ��\n[1;31m$NĬ������񹦵Ŀھ�����ǿ����ǿ������ɽ�ԡ����������ᣬ�����մ󽭡���\n[1;31mɲ�Ǽ�ֻ��$Nȫ���ʱ���ֳ�һ����͵ľ�����[2;37;0m\n");
	set("remove_msg", "[1;33mһ����⻮����$N���ϵĳ��������������ʧ������[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
