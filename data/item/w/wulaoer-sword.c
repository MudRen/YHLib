// ITEM Made by player(���϶�:wulaoer) /data/item/w/wulaoer-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu May 02 05:12:29 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m����[1;36m����[1;37m��[2;37;0m", ({ "sword" }));
	set_weight(6750);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m�׻𺮾�[2;37;0m���ƶ��ɵ�һ������
[1;37m�����ĳ߶��磬�ڽ���һ���ط�ڿ����Ÿ���βָ��������С�ף�ͨ��[1;36m���ӨӨ[1;37m������������������š�[2;37;0m
�����Ͽ���һ��С�֣����϶�(wulaoer)
");
	set("value", 2100000);
	set("point", 301);
	set("material", "stone");
	set("wield_msg", "[1;37m$N������ָ����������ǰ�ߴ�֮������һ��[1;33m��â��[1;37m������������ǰ̽����[1;33m��â��[1;37m����������һ��$n��[2;37;0m\n");
	set("unwield_msg", "$n[1;37m��$N���ϲ�����������ʼʱХ���������ޣ�ת�ۻ�����������ʡ���ǱԨ����Ʈ������������Ľ�Х�ƿն�ȥ��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
