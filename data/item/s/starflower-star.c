// ITEM Made by player(����:starflower) /data/item/s/starflower-star.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Mar 27 06:51:23 2003
#include <ansi.h>
#include <weapon.h>

inherit WHIP;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m�����߻�[2;37;0m", ({ "star" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ���ޡ�
[1;31m��Ц��ӭ�ˣ���ѩ�㿰ϧ������Ӱ������㳯�³ࡣ[2;37;0m
�ޱ��Ͽ���һ��С�֣�����(starflower)
");
	set("value", 2000000);
	set("point", 135);
	set("material", "stone");
	set("wield_msg", "[1;31m��ҡ�����ɦͷ��������ʤĪ��������������֣���֪��Ůл������[2;37;0m\n");
	set("unwield_msg", "[1;31mǧ�����Ӳβ�������ʱ��ȴ�����½���پƻᣬ��ͤΩԸһ������[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_whip(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
