// ITEM Made by player(����֮��:sunshine) /data/item/s/sunshine-firejian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Jul 11 04:29:47 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m��[1;37m֮[1;36m��[2;37;0m", ({ "firejian" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[2;37;0m���ƶ��ɵ�һ������
[1;37m�������߶��磬����ʮ�Ľ���������ϵ�������ɢ�������ȵ�[1;31m����[1;37m��[2;37;0m
�����Ͽ���һ��С�֣�����֮��(sunshine)
");
	set("value", 2200000);
	set("point", 387);
	set("material", "stone");
	set("wield_msg", "[1;37m$N���ְ���[1;36m��[1;31m��[1;36m��[1;37m��[1;36m��[1;37m�ϣ��ھ�һ�ţ�ֻ��һ����������$N����ͻȻ�ֳ�һ��[1;31m���[1;37m�����С�[2;37;0m\n");
	set("unwield_msg", "[1;37m$N���ֳֽ����ֱȻ��ţ�������������ʪ�������ǣ�һ��紵����$n[1;37m��Ȼƾ����ʧ����Ӱ�����ˡ�[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
