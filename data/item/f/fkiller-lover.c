// ITEM Made by player(����ʬ:fkiller) /data/item/f/fkiller-lover.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu May 02 06:02:58 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m���·�˪[2;37;0m", ({ "lover" }));
	set_weight(6750);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m�׻𺮾�[2;37;0m���ƶ��ɵ�һ������
[1;37m����һ����̬����ͨ��ѩ�ף������޳������������΢΢��������â��������[2;37;0m
�����Ͽ���һ��С�֣�����ʬ(fkiller)
");
	set("value", 2100000);
	set("point", 133);
	set("material", "stone");
	set("wield_msg", "[1;37m$N����һ����̾�������شӽ����н������γ�����ʱ��ؼ�������һ��������Ϣ��ɱ����\n�ڳ�����ֻ����������ë���Ȼ�����ɸ�̾���侹�����������[2;37;0m\n");
	set("unwield_msg", "[1;37m$N����΢΢һ�𱦽���Ȼ���ʣ���������ɱ��˲�䵴Ȼ�޴棬\n�ڳ�������ͷһ�ɣ����ɳ���һ����[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
