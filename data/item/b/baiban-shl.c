// ITEM Made by player(�װ�:baiban) /data/item/b/baiban-shl.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Jul 21 17:24:34 2002
#include <ansi.h>
#include <weapon.h>

inherit WHIP;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m��ˮ��[2;37;0m", ({ "shl" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ���ޡ�
[1;31m������
[1;34m��ľ������ĵ�ƨ��[1;36m
��ģ�
�����������ƣ�
[1;33m���˰ɣ����ǵ�[2;37;0m
�ޱ��Ͽ���һ��С�֣��װ�(baiban)
");
	set("value", 2000000);
	set("point", 111);
	set("material", "stone");
	set("wield_msg", "$N�ó�����������ƽ��������[2;37;0m\n");
	set("unwield_msg", "[1;37m$N�����Ĵ�ˮ�س�������õı޿��˿��������˵���ܺã��ܺá�[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_whip(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
