// ITEM Made by player(���:cooky) /data/item/c/cooky-flower.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Oct 20 07:53:29 2002
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m����[2;37;0m", ({ "flower" }));
	set_weight(2400);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ��ս�¡�
[1;37m��������һЦ������������ů�త���ճ�������¥̨��
[1;37m��ˮ���������ޣ�������������Ь���۱�ǣϵ��������[2;37;0m
ս��Ե�Ͽ���һ��С�֣����(cooky)
");
	set("value", 2000000);
	set("point", 90);
	set("material", "stone");
	set("wear_msg", "[1;37mѰѰ���٣��������壬����Ҳ����ݡ�\n[1;37mէů����ʱ�����ѽ�Ϣ��������յ���ƣ��������������缱��\n[1;37m���Ҳ�������ģ�ȴ�Ǿ�ʱ��ʶ��[2;37;0m\n");
	set("remove_msg", "[33m$N[33m������[1;37m����[2;37;0m[33m��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
