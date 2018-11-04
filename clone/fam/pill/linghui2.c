#include <ansi.h>
#include "pill.h"

void create()
{
        set_name(HIW "��쵤" NOR, ({ "haotian dan", "haotian", "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "����һ�ž������ɵ���쵤�����ú���������ۡ�\n" NOR);
                set("base_unit", "��");
                set("base_value", 10000);
                set("base_weight", 50);
                set("only_do_effect", 1);

        }
        setup();
}

int do_effect(object me)
{
        int na, un;

        na = query("name");
        un = query("base_unit");

        if (time() - me->query_temp("last_eat/dan(linghui)") < 200)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }
        me->set_temp("last_eat/dan(linghui)", time());

        message_vision(HIY "$N" HIY "һ������������һ" + un + na +
                       HIY "��\n" NOR, me);
        me->add("magic_points", 12 + random(14));

        me->start_busy(3);
        add_amount(-1);

        if (query_amount() < 1)
                destruct(this_object());

        return 1;
}
