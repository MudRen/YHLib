// ITEM Made by player(����:mong) /data/item/m/mong-mcloth.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Oct 12 19:08:15 2002
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m�������װ[2;37;0m", ({ "mcloth" }));
	set_weight(2400);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ��ս�¡�
����һ������ɫս�£�����ı������ҫ�۵Ĺ������Ǵ�˵�е�������[1;36m�������װ[2;37;0m��[2;37;0m
ս��Ե�Ͽ���һ��С�֣�����(mong)
");
	set("value", 2000000);
	set("point", 169);
	set("material", "stone");
	set("wear_msg", "$N�����Ĵ���[1;36m�������װ[2;37;0m��[2;37;0m\n");
	set("remove_msg", "$N����������[1;36m�������װ[2;37;0m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
