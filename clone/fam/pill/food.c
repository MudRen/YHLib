#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
        set_name(NOR + WHT "����" NOR, ({ "gan liang", "gan", "liang" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", NOR + WHT "����һ�����Я���ĸ�����\n" NOR);
                set("base_unit", "��");
                set("base_value", 50);
                set("base_weight", 10);
                set("only_do_effect", 1);
        }
        setup();
        set_amount(1);
}

int do_effect(object me)
{
	if (me->query("food") >= me->max_food_capacity())
        {
                write("���Ѿ���̫���ˣ���Ҳ�������κζ����ˡ�\n");
                return 1;
        }

        message_vision("$N����һ��" + name() + "���˼��ڡ�\n" NOR, me);
        me->add("food", 100);

        add_amount(-1);

        if (query_amount() < 1)
                destruct(this_object());

        return 1;
}
