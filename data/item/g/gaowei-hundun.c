// ITEM Made by player(��Ӱ�:gaowei) /data/item/g/gaowei-hundun.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Sep 25 02:53:38 2002
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[35m����[2;37;0m", ({ "hundun" }));
	set_weight(2550);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ��ͷ����
[35m�����Ϲ�����֮һ����˸�������Ϲ��ͷ����֪�ɺ�����������������Ҳ���������ֺ���[2;37;0m
ͷ��Ե�Ͽ���һ��С�֣���Ӱ�(gaowei)
");
	set("value", 2000000);
	set("point", 58);
	set("material", "stone");
	set("wear_msg", "[35m$N����ͻȻ��һ�Ż���������������Χ����������ʧ��ʱ����ͷ���Ѿ�����һ��������¶���Ϲ��ͷ��[2;37;0m\n");
	set("remove_msg", "[1;36mһ����⻮����$Nͷ�ϵ�ͷ���ƺ����������ʧ�����ˡ�[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
