// ITEM Made by player(����:lph) /data/item/l/lph-blade.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Oct 13 12:50:48 2002
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31mѪ����[2;37;0m", ({ "blade" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ�ѵ���
[1;31m����һ�ѳ���Ѫ��ζ�ı�����������һͷѪ�ǵ�Ӱ���������֣�������Ǵ�˵�е�Ѫ���С�[2;37;0m
�����Ͽ���һ��С�֣�����(lph)
");
	set("value", 2000000);
	set("point", 135);
	set("material", "stone");
	set("wield_msg", "[1;31m�ǵ�ʮ������ѧ��\n��н��������һ����֪֮��˳ˮ����ͬ��ͬ��\n������һ֪��֪���������������������ɿɹ�\n[2;37;0m\n");
	set("unwield_msg", "[1;31m$N���³��ƣ�\n����һƥ���Ա������ǣ�\nѪɫ���ǣ�\n[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
