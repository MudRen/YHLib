// ITEM Made by player(����:mong) /data/item/m/mong-tjian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jul  1 23:40:47 2002
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m���콣[2;37;0m", ({ "tjian" }));
	set_weight(15000);
	set("item_make", 1);
	set("unit", "��");
	set("long", "������[1;37m����쾧[2;37;0m���ƶ��ɵ�һ������
[1;36mһ�鴿��ɫ����ˮ������Ө��͸����Ͼ�ı������ҫ�۵Ĺ������з·��̲���ǧǧ�����������
����������Ϣ��ɢ�������������������Ǵ�˵�е�����[1;37m���콣[2;37;0m��[1;36m�ഫֻ�����칬�вŻ���֡�[2;37;0m
�����Ͽ���һ��С�֣�����(mong)
");
	set("value", 4200000);
	set("point", 481);
	set("material", "tian jing");
	set("wield_msg", "[1;36m���ɫ���У���غ�Ȼ���죬�·������������ס�\n$N�������죬��ɫɷ����ѩ��������У�[1;37m���콣[2;37;0m[1;36mӭ����ʣ��⻪��ʢ�У��׺���ն��롣[2;37;0m\n");
	set("unwield_msg", "[1;36m$N�������졣���ѹ��ʣ����������졣\n[1;37m������֮�������⣬�ΰ���֮������[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
