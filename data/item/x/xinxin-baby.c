// ITEM Made by player(ɽ������:xinxin) /data/item/x/xinxin-baby.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Oct 12 12:37:32 2002
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;35m��[1;36m��[34mս[32m��[2;37;0m", ({ "baby" }));
	set_weight(2400);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ��ս�¡�
����ǹ����͸���޵�ս�£����������е��޳�֮ͽ���˱����ᡣ������������������������ָ�����������ı���������ֻӦ�����У��˼����м��غϣ�[2;37;0m
ս��Ե�Ͽ���һ��С�֣�ɽ������(xinxin)
");
	set("value", 2000000);
	set("point", 125);
	set("material", "stone");
	set("wear_msg", "[33m$N[33mװ��[1;35m��[1;36m��[34mս[32m��[2;37;0m[33m��[2;37;0m\n");
	set("remove_msg", "[33m$N[33m������[1;35m��[1;36m��[34mս[32m��[2;37;0m[33m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
