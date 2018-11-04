#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW "�������" NOR, ({"tianyi shenjiu", "jiu", "shenjiu", "tianyi"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIW "����һƿ������ƣ�����ֻ����Ҳ����������\n" NOR);
                set("unit", "ƿ");
                set("no_sell", 1);
                set("value", 50000);
        }
        setup();
}

void init()
{
        add_action("do_eat", "drink");
}

int do_eat(string arg)
{
        object ob;
        object me = this_player();

        if (! id(arg) && arg != "tianyi shenjiu"
           && arg != "jiu" && arg != "shenjiu"
           && arg != "tianyi")
                return notify_fail("��Ҫ��ʲô������\n");

        if (me->is_busy())
                return notify_fail("��ʲô��С�ı�ҭ���ˡ�\n");

        if (random(30) > 1)
        {
                message_vision(WHT "$N" WHT "���˼��ڣ�ȴ����ƿ����װ��"
                               "������ͨ��Ů���졣\n" NOR, me);
                destruct(this_object());
                return 1;
        }

        message_vision(HIW "$N" HIW "һ��ͷ����������ƺ�����ȥ�������"
                       "ʱΪ֮һ��\n" NOR, me);

        me->set("jingli", me->query("max_jingli"));
        me->set("neili", me->query("max_neili"));
        me->set("jing", me->query("max_jing"));
        me->set("qi", me->query("max_qi"));
        me->set("eff_jing", me->query("max_jing"));
        me->set("eff_qi", me->query("max_qi"));
        me->improve_skill("force", 300000);

        me->affect_by("drunk", ([
                "level" : 500 + random(500),
                "id"    : me->query("id"),
                "duration" : 500 + random(500)
        ]));

        me->start_busy(6);
        destruct(this_object());
        return 1;
}

