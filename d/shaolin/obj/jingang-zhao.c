// jingang-zhao.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;
inherit F_NOCLONE;

void create()
{
	set_name("�����", ({ "jingang zhao", "zhao" }));
	set_weight(2000);
	set("unit", "��");
	set("long", @LONG
����һ��������������ģ�ͨ������ɽѩ��˿֯�ɣ������ޱȵ���
�����ˡ�������������ǰ�ɴ�Ħ����Я����ԭ��аħ��֮���ף���
�Ƿ�����Ͻ�ħ������
LONG );
	set("material", "cloth");
	set("value",1000000);
	set("no_sell", 1);
	set("wear_msg", HIY "ֻ����������һ����$Nչ��һ����������������������ϡ�
˲ʱ������Ϊ֮ʧɫ������ǧ�������ƶ�䣬һ��ׯ������\n" NOR);
	set("remove_msg", HIY "$N������ִ����������������۵���СС��һ�š�\n" NOR);
	set("armor_prop/armor", 220);
        set("stable", 0);
	setup();
        check_clone();
}
