#include <armor.h>
#include <ansi.h>

inherit CLOTH;
inherit F_NOCLONE;

void create()
{
    	set_name(NOR + YEL "���ս��" NOR, ({ "feituo jinjia", "feituo", "jinjia", "armor", "jia", }) );
        set_weight(10000);
        set("unit", "��");
      	set("long", YEL "����һ���ûƽ������ɵĻ��ף����ϵ���ű�����\n"
                    "������ա���˵��ֻ�и߲������ſ�ʹ�÷��ձ�ǡ�\n" NOR);
        set("material", "cloth");
        set("value",1000000);
        set("no_sell", 1);
        set("armor_prop/dodge", -30);
        set("armor_prop/armor", 200);
        set("stable", 0);
        setup();
        check_clone();
}
