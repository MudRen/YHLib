// ITEM Made by player(����:qiangren) /data/item/q/qiangren-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat May 04 22:46:54 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[36m�������콣[2;37;0m", ({ "sword" }));
	set_weight(30000);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[36m��ɽ����[2;37;0m���ƶ��ɵ�һ������
[1;36m�������ߣ������֮�������ɽ�ʦ�ɽ��������������й��ģ�������⵴���������ޱȡ�[2;37;0m
�����Ͽ���һ��С�֣�����(qiangren)
");
	set("value", 2200000);
	set("point", 207);
	set("material", "stone");
	set("wield_msg", "[1;36m$Nһ����Х����������һ���������콣��������ˮ���������������[2;37;0m\n");
	set("unwield_msg", "[1;36m$N����һ����̾��������ȥ�������콣�����ϵ�Ѫ�������ֲ��뽣�ʡ�[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
