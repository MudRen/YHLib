#include <ansi.h>
#include "pill.h"

void create()
{
        set_name(HIY "����" NOR, ({ "haotian guo", "haotian", "guo" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIY "����һö���ɫ�Ĺ�ʵ�����ú��������˵���ۡ�\n" NOR);
                set("base_unit", "ö");
                set("base_value", 6000);
                set("base_weight", 80);
                set("only_do_effect", 1);

        }
        setup();
}

int do_effect(object me)
{
        int na, un;

        na = query("name");
        un = query("base_unit");

        if (time() - me->query_temp("last_eat/dan(linghui)") < 100)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }
        me->set_temp("last_eat/dan(linghui)", time());

        message_vision(HIY "$N" HIY "һ������������һ" + un + na +
                       HIY "��\n" NOR, me);
        me->add("magic_points", 5 + random(6));

        me->start_busy(3);
        add_amount(-1);

        if (query_amount() < 1)
                destruct(this_object());

        return 1;
}
