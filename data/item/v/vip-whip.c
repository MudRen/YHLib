// ITEM Made by player(����:vip) /data/item/v/vip-whip.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Oct 19 17:39:33 2002
#include <ansi.h>
#include <weapon.h>

inherit WHIP;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m���[2;37;0m", ({ "whip" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ���ޡ�
[1;33m�����������ĳ��ޣ���˵����ǰ����һ��С����ֻҪ�����еĶ���������𣬰����˵����塣[2;37;0m
�ޱ��Ͽ���һ��С�֣�����(vip)
");
	set("value", 2000000);
	set("point", 149);
	set("material", "stone");
	set("wield_msg", "[1;31m$NĬ������񹦵Ŀھ�����ǿ����ǿ������ɽ�ԡ����������ᣬ�����մ󽭡���\nɲ�Ǽ�ֻ��$Nȫ���ʱ���ֳ�һ����͵ľ�������$Nȫȫ���֡�\n$N���о��������������ɨ�����ܣ�һ�ɺ�����Ȼ����[2;37;0m\n");
	set("unwield_msg", "[1;31m$N΢һ������������񹦣������������ڵ���֮�У����澭�����鲼ȫ��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_whip(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
