inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_drink", "drink");
}

void create()
{
        set_name(HIC "��" HIW "��" HIC "��" HIR "��"
                 HIC "��" NOR, ({ "xuanbing jiu", "xuanbing", "jiu" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIC "����һ�����֮���������̻�ơ�\n" NOR);
                set("value", 50000);
        }
        setup();
}

int do_drink(string arg)
{
        object me = this_player();

        if (! arg || ! id(arg))
                return notify_fail("��Ҫ��ʲô������\n");

        if (me->is_busy())
                return notify_fail("��ʲô��С�ı�ҭ���ˡ�\n");

        message_vision(HIC "$N" HIC "һ��ͷ������ƿ" + name() +
                       HIC "������ȥ��\n" NOR, me);

        if (! me->query("skybook/item/xuanbingjiu"))
        {
                message_vision(HIB "ͻȻ��$N" HIB "��ɫ����һ�䣬�䲻����"
                               "�˼�����ս��\n" NOR, me);
                me->apply_condition("xuanbing-jiu", 50 + random(50));

        } else
        {
                message_vision(HIW "$N" HIW "һ���������������������໥��"
                               "�棬�������ڶ���\n" NOR, me);

                if (me->can_improve_skill("force"))
                        me->improve_skill("force", 100000);

                if (me->query_skill_mapped("force") == "luohan-fumogong"
                   && me->can_improve_skill("luohan-fumogong"))
                        me->improve_skill("luohan-fumogong", 100000);

                me->add("skybook/item/xuanbingjiu", 1);

                me->start_busy(6);
        }
        destruct(this_object());
        return 1;
}
