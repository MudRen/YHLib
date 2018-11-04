#include <ansi.h> 
inherit ITEM;

void create()
{
        set_name(NOR + GRN "�ߵ���" NOR, ({ "shedan fen", "shedan", "fen" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", GRN "����һ���������˵��ߵ��ۡ�\n" NOR);
                set("value", 2000);
                set("only_do_effect", 1);
        }
        setup();
}

int do_effect(object me)
{
        if (me->query("eff_qi") >=  me->query("max_qi") - 20)
                return notify_fail("��������Ѫ��ӯ������Ҫ���ߵ��ۡ�\n");

        if (random(2) == 0)
        {
                message_vision(WHT "$N" WHT "����һ���ߵ��ۣ�����"
                               "���������ۣ������ϵ���\n" NOR, me);
                destruct(this_object());
                return 1;
        }
        me->add("qi", 30);
        me->add("eff_qi", 20);
        message_vision(HIY "$N" HIY "����һ���ߵ��ۣ��پ�������ӿ"
                       "���������Щ��\n" NOR, me);
        destruct(this_object());
        return 1;
}
