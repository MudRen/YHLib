#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(GRN "�ϳ���" NOR, ({"duanchang cao", "duanchang", "cao"}));
        set("unit", "��");
        set("long", GRN "����һ����˸���׹��С�ݡ�\n" NOR);
        set("value", 10);
        set_weight(100);
        set("only_do_effect", 1);
        setup();
}

int do_effect(object me)
{
        message_vision("$Nһ���������ϳ������������С�\n", me);
        me->set_temp("die_reason", "���˶ϳ���ȥ���ڰ��޳���");
        me->die();
        destruct(this_object());
        return 1;
}

