#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("ľ��", ({ "mu jian","jian" }));
	set_weight(800);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ������֦���ɵ�ľ����\n");
		set("value", 50);
		set("material", "wood");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(1);
	setup();
}

