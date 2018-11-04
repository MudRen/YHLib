// ITEM Made by player(С��:abc) /data/item/a/abc-xuezhi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Aug 22 10:46:27 2002
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[31mѪָ[2;37;0m", ({ "xuezhi" }));
	set_weight(1190);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ��ָ�ס�
[31m����һֻ��ָ�����������ѪҺ��ĺ�ɫ��[2;37;0m
ָ��Ե�Ͽ���һ��С�֣�С��(abc)
");
	set("value", 2000000);
	set("point", 173);
	set("material", "stone");
	set("wear_msg", "[1;31m΢Ц������������ʳָ���ڿ��У�ֻ�������ꡱһ��������ʳָ�Ѿ���ʧ����Ѫֻ�ӶϿ��������������һ�䣬�������֣������ģ�һ��Ѫ���ʳָ�ֳ������������ϡ�[2;37;0m\n");
	set("remove_msg", "[1;32m�ӻ����ó�һֻ���֣�һ��ҧ��ʳָ����������һ����Ѫ��ָ�ԶϿ�����ͻȻ���ѣ������ִӿ���ȡ����ָ��Ѹ�ٰ����˿��ϣ�ֻ���׹�һ������ָ�����Ľ��ڶϿ��ϣ�ֻ���µ����ĺ�˿��[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/finger", 10);
	set("armor_prop/claw", 10);

	setup();
}

string long() { return query("long") + item_long(); }
