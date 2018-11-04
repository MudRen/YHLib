#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name(HIY "�����" NOR, ({ "yufeng mi", "yufeng", "mi"}));
        set_weight(750);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIY "����һ�������ɵ��ۣ��ɽ���䶾��\n" NOR);
                set("unit", "��");
                set("value", 500);
                set("no_sell", 1);
                set("mi_count", 5);
                set("only_do_effect", 1);
        }
        setup();
}

int do_effect(object me)
{
        if (query("mi_count") < 1)
        {
                write("�������������Ѿ����ȵ�һ�β�ʣ�ˡ�\n");
                return 1;
        }

        if (me->query("water") >= me->max_water_capacity()
           && me->query("food") >= me->max_food_capacity())
        {
                write("���Ѿ���̫���ˣ���Ҳ�������κζ����ˡ�\n");
                return 1;
        }

        message_vision("$N������ӣ���ཹ�����¼�������ۡ�\n" NOR, me);
        me->add("food", 50);
        me->add("water", 50);

        if ((int)me->query_condition("yufengdu"))
        {
                me->clear_condition("yufengdu");
                tell_object(me, HIC "��ֻ�����ڲд����䶾����"
                                    "���ˣ�������֮һ����\n" NOR);
        }
        add("mi_count", -1);
        return 1;
}
