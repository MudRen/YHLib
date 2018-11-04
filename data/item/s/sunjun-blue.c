// ITEM Made by player(���:sunjun) /data/item/s/sunjun-blue.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Jun 15 19:01:45 2002
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[35m�����[2;37;0m", ({ "blue" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[1;31m���޳�[2;37;0m���ƶ��ɵ�һ�Ż��ס�
[1;32m��[35m�����[1;32m���ǲ�ηˮ����е������һλ����ǰ����ʮ��ǰ�����³ɯ���ɵ���ʮ��ö[35m�����˿��[1;32m֯�ɵ�һ�����¡�[2;37;0m
����Ե�Ͽ���һ��С�֣����(sunjun)
");
	set("value", 2000000);
	set("point", 103);
	set("material", "stone");
	set("wear_msg", "[1;36mֻ��[1;32m$N[1;36m�������£�ͻȻ�����ƵĹ��ǿ������չ�����֮�£���ɫ���ƺ�������[35m��[1;36m��[1;33m��[1;36m��[36m��[1;36m��[1;37m��[1;36m��[31m��[1;36m��[33m��[1;36m�ĸ�����ɫ����ҫ������[2;37;0m\n");
	set("remove_msg", "[1;31mֻ��[1;37m$N[1;31m�����ﴦ������һƬ���⣬����[35m�����[1;31m������ͻȻ��ն�����ƮƮ����������֮�ߣ��������棬����Ʈ����������һֻ�ʷ[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
