// ITEM Made by player(���϶�:wulaoer) /data/item/w/wulaoer-mail.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jul 15 20:42:15 2002
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m����[2;37;0m", ({ "mail" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ�Ż��ס�
[1;37m��[2;37;0m��[1;36m����[2;37;0m��[1;37m�û����ɵ�һ�׻��ף�������Լɢ���ŵ����Ĺ�â��[2;37;0m
����Ե�Ͽ���һ��С�֣����϶�(wulaoer)
");
	set("value", 2000000);
	set("point", 200);
	set("material", "stone");
	set("wear_msg", "[1;37m$N�ӱ��������İѽ�������һ��[2;37;0m��[1;36m��[2;37;0m��[1;37m���������̹⻯��һ�׻��ס�[2;37;0m\n");
	set("remove_msg", "[1;36m�����������ؽ�[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
