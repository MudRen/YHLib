// ITEM Made by player(���:cooky) /data/item/c/cooky-mao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Feb 24 15:38:56 2003
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[37m����[2;37;0m", ({ "mao" }));
	set_weight(30000);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[2;37;0m[36m��ɽ����[2;37;0m���ƶ��ɵ�һ������
[37m�����м��ˣ��ľ��ڿչȡ���������Ц�����ž��˿ޡ�[2;37;0m
�����Ͽ���һ��С�֣����(cooky)
");
	set("value", 2200000);
	set("point", 188);
	set("material", "stone");
	set("wield_msg", "[37m������ݺ��ȥ��ϸ�㸡��ǧ���������ڴ��μ���ʱ��ɢ���������ٴ���[2;37;0m\n");
	set("unwield_msg", "[37m���ٽ��������£������������ס��Ȱ��Ī�������ˣ�������Ӧ������[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
