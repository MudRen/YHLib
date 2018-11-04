// ITEM Made by player(���:cooky) /data/item/c/cooky-lipper.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Jan 10 14:14:25 2003
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m����[2;37;0m", ({ "lipper" }));
	set_weight(1190);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ��ָ�ס�
[1;37m�����������޲����ٳ�¥��ˮ���졣��Ů�ض�����䣬����˪�ﶷ濾ꡣ[2;37;0m
ָ��Ե�Ͽ���һ��С�֣����(cooky)
");
	set("value", 2000000);
	set("point", 157);
	set("material", "stone");
	set("wear_msg", "[1;37m�쪶���ϸ������ܽ�����������ס�������������룬��ǣ˿�����ء�[2;37;0m\n");
	set("remove_msg", "[1;37m���Ͽ��������٣��������κ���š�����Ī����������һ����˼һ��ҡ�[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/finger", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/claw", 10);
	set("armor_prop/armor", 10);

	setup();
}

string long() { return query("long") + item_long(); }
