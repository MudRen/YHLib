// ITEM Made by player(����:kong) /data/item/k/kong-jingtian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Jul  2 00:05:29 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m����ָ[2;37;0m", ({ "jingtian" }));
	set_weight(3500);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m����쾧[2;37;0m���ƶ��ɵ�һ��ָ�ס�
[1;36mһ�鴿��ɫˮ��ָ�ף���Ө��͸����Ͼ�ı������ҫ�۵Ĺ������з·��̲���ǧǧ���������������������Ϣ��ɢ�������������������Ǵ�˵�е�������������ָ���ഫֻ�����칬�вŻ���֡�[2;37;0m
ָ��Ե�Ͽ���һ��С�֣�����(kong)
");
	set("value", 4200000);
	set("point", 474);
	set("material", "tian jing");
	set("wear_msg", "[1;36m$N��ָһ������ָ��һ�������������졣���Ϊ֮�𺳡�[2;37;0m\n");
	set("remove_msg", "[1;36m$N����һ����̾��������ȥ����ָ�ϵ�Ѫ���������������ϡ�[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/finger", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/claw", 10);

	setup();
}

string long() { return query("long") + item_long(); }
