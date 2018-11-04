#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "drink");
}

void create()
{
        set_name(HIW "������" NOR, ({"mengpo tang", "soup", "tang"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "һ���������ڵ���������ɢ����Ũ�ҵĲ�ҩ��ζ��\n");
                set("unit", "��");
                set("only_do_effect", 1);
        }
        setup();
}

int do_eat(string arg)
{
        object ob;
        object me = this_player();
        int max;

        if( me->is_busy() )
                return notify_fail("��ʲô��С�ı�ҭ���ˡ�\n");

        me->set_temp("last_eat/mengpo_tang", time());

        message_vision(HIW "$N" HIW "һ��ͷ����������ȫ��������ȥ������Ϊ֮һ��\n" NOR, me);

        me->set("jingli",me->query("max_jingli"));
        me->set("neili",me->query("max_neili"));
        me->set("jing",me->query("max_jing"));
        me->set("qi",me->query("max_qi"));
        me->set("eff_jing",me->query("max_jing"));
        me->set("eff_qi",me->query("max_qi"));

        max = me->max_food_capacity();
        me->set("food", max);
        max = me->max_water_capacity();  
        me->set("water", max);
        me->clear_condition();

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
