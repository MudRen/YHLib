#include <ansi.h>
#include "pill.h"

void create()
{
        set_name(HIR "���" NOR, ({ "zhu guo", "zhu", "guo", "zhuguo" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIR "����һö���ɫ����������𵽵�Ϣ���������á�\n" NOR);
                set("base_unit", "ö");
                set("base_value", 3000);
                set("base_weight", 80);
                set("only_do_effect", 1);
        }
        setup();
}

int do_effect(object me)
{
        int na, un;
        mapping my;

        na = query("name");
        un = query("base_unit");

        if (time() - me->query_temp("last_eat/dan(D)") < 240)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }

        if (me->query("neili") >= me->query("max_neili"))
        {
                write("������������Ϊ�������" + name() + "��\n");
                return 1;
        }

        my = me->query_entire_dbase();

        me->set_temp("last_eat/dan(D)", time());

        message_vision(HIY "$N" HIY "����һ" + un + na + HIY "����Ϣ�õ���"
                       "��ȫ�Ĳ��䡣\n" NOR, me);

        my["neili"] = my["max_neili"];

        me->start_busy(3);
        add_amount(-1);

        if (query_amount() < 1)
                destruct(this_object());

        return 1;
}
