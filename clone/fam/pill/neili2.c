#include <ansi.h>
#include "pill.h"

void create()
{
        set_name(HIR "������" NOR, ({ "huolong guo", "huolong", "guo" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIR "����һöȭͷ��С�Ļ����������𵽵�Ϣ���������á�\n" NOR);
                set("base_unit", "ö");
                set("base_value", 8000);
                set("base_weight", 100);
                set("only_do_effect", 1);
        }
        setup();
}

int do_effect(object me)
{
        int na, un;

        na = query("name");
        un = query("base_unit");

        if (time() - me->query_temp("last_eat/dan(D)") < 400)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }

        if (me->query("neili") >= me->query("max_neili") * 2)
        {
                write("������������Ϊ�������" + name() + "��\n");
                return 1;
        }

        me->set_temp("last_eat/dan(D)", time());

        message_vision(HIY "$N" HIY "����һ" + un + na + HIY "��˫Ŀ��ʱ��"
                       "�����䡣\n" NOR, me);

        me->set("neili", me->query("max_neili") * 2);

        me->start_busy(5);
        add_amount(-1);

        if (query_amount() < 1)
                destruct(this_object());

        return 1;
}
