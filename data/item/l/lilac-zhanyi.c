// ITEM Made by player(����:lilac) /data/item/l/lilac-zhanyi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Aug 19 14:49:48 2002
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[37mĺɫ[2;37;0m", ({ "zhanyi" }));
	set_weight(2400);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ��ս�¡�
[1;32m���ڶ�ʮ����һ���ƻ���
[1;32m��ʲô������ҹ����
[1;32m����ʹ��������Ȼ����
[1;32mɽ����Ӧ��ֱ������

[1;32m�ع���������
[1;32m�ԲԺ��ŵĴ�΢
[1;32m������Ŀ�����
[1;32m��ĺɫ�о���Ϊ���۵�����[2;37;0m
ս��Ե�Ͽ���һ��С�֣�����(lilac)
");
	set("value", 2000000);
	set("point", 141);
	set("material", "stone");
	set("wear_msg", "[1;37m��һ�������ҹ��\n[1;37m����һ�׸�\n[1;37m��䣲���\n[1;37m��ɽ������ٺ�[2;37;0m\n");
	set("remove_msg", "[1;31m�ٿ���ʱȴ��Ϣ����\n[1;31m�����ټ�����������\n[1;31m�������¹����˼���[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
