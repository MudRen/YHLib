#include <ansi.h>
#include "pill.h"

void create()
{
        set_name(NOR + YEL "�����ҩ" NOR, ({ "huogu lingyao", "huogu", "lingyao", "yao" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", YEL "����һ���ӽ�ɫ��ҩ�裬�������б���Ϊ������ʥҩ��\n" NOR);
                set("base_unit", "��");
                set("base_value", 10000);
                set("base_weight", 55);
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

        if (time() - me->query_temp("last_eat/dan(full)") < 240)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }

        my = me->query_entire_dbase();

        me->set_temp("last_eat/dan(full)", time());

        message_vision(HIY "$N" HIY "����һ" + un + na + HIY "����Ҳ�о�"
                       "�����κ�ƣ����\n" NOR, me);

        my["jing"]   = my["max_jing"];
        my["qi"]     = my["max_qi"];
        my["eff_jing"] = my["max_jing"];
        my["eff_qi"]   = my["max_qi"];

        me->start_busy(5);
        add_amount(-1);

        if (query_amount() < 1)
                destruct(this_object());

        return 1;
}
