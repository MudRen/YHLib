// ITEM Made by player(л����:china) /data/item/c/china-dreamhat.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Oct 14 13:15:24 2002
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m�Իþ���[2;37;0m", ({ "dreamhat" }));
	set_weight(2550);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ��ͷ����
[1;33mһ�����ɫ��ñ�ӣ��ƺ�����ĳ��ħ����[2;37;0m
ͷ��Ե�Ͽ���һ��С�֣�л����(china)
");
	set("value", 2000000);
	set("point", 67);
	set("material", "stone");
	set("wear_msg", "[1;33m$N���������Իþ��ڡ�\n��ʱ�����$N����ʵ�һ�㣬��ʱ˫ϥ�����̲�ס��ͷ��ݣ����д������������꣬�����꣡��\n[2;37;0m\n");
	set("remove_msg", "[1;33m$N����ժ���Իþ��ڡ�\n����ѽ��һ������̱���ڵأ���������������μ�����������\n[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
