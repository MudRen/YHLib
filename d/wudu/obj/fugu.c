#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(WHT "���ǲ�" NOR, ({"fugu cao", "fugu", "cao"}));
        set("unit", "��");
        set("long", WHT "����һ����ͨ��С�ݣ�Ҷ�淢��һ�����ŵĳ�����\n" NOR);
        set("value", 10);
        set_weight(100);
        set("only_do_effect", 1);
        setup();
}

int do_effect(object me)
{
        message_vision("$Nһ�����������ǲ����������С�\n", me);
        me->set_temp("die_reason", "���˸��ǲ�ȥ���ڰ��޳���");
        me->die();
        destruct(this_object());
        return 1;
}

