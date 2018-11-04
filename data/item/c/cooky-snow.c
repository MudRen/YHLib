// ITEM Made by player(���:cooky) /data/item/c/cooky-snow.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Oct 10 12:21:45 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m����[2;37;0m", ({ "snow" }));
	set_weight(1190);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ��ָ�ס�
[1;36mϪ�߰��ء�������ꡣϪ������������������������㣬Ҫ���ҡ���Ȼһ����
[1;36m��ɳԶ�֡������価�ʣ��Ϻ�����衣�ξ���ȥ��ʱ������ͷ�ϡ��紵һ�ơ�[2;37;0m
ָ��Ե�Ͽ���һ��С�֣����(cooky)
");
	set("value", 2000000);
	set("point", 144);
	set("material", "stone");
	set("wear_msg", "[1;36m��紵�꣬ս�ºɡ����������赡�˭�������ձ������ƽ��캭���̡�\n[1;36m���񷭿գ����㴵�ˣ��߳��ϸ�ϯ�����к���������һ��ǧʯ��[2;37;0m\n");
	set("remove_msg", "[1;36mң�봦ʿ������������ȥ���������ɲ���é��������ڷ������ѷǳ�����\n[1;36m��˵���꣬����¥�£�ˮ���ƿ�խ���������ʣ��ϳ���Ҷ��Ϣ��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/claw", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/finger", 10);

	setup();
}

string long() { return query("long") + item_long(); }
