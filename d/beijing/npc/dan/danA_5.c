#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
        set_name(HIY "�Żʲ��ĵ�" NOR, ({ "buxin dan", "dan" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("base_unit", "��");
                set("base_value", 150);
                set("only_do_effect", 1);
        }
        setup();
        set_amount(1);
}

int do_effect(object me)
{
        mapping my;

        if (time() - me->query_temp("last_eat/dan(A)") < 30)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }

        my = me->query_entire_dbase();
        if (my["jing"] == my["max_jing"])
        {
                write("�����ھ���״̬�ܺã��������" + name() + "��\n");
                return 1;
        }

        me->set_temp("last_eat/dan(A)", time());

        message_vision(HIY "$N����һ���Żʲ��ĵ�������һ��������ȡ�\n" NOR, me);
        me->receive_curing("jing", 800);
        me->receive_heal("jing", 800);

        me->start_busy(3);

        add_amount(-1);
        if (query_amount() < 1)
                destruct(this_object());

        return 1;
}
