#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
���ɽ�������ֲ�����ָ���ڳ�������ôҲ�Ʋ�����
LONG);
        setup();
}

void init()
{
        add_action("do_use", "use");
        add_action("do_tiao", "tiao");
        add_action("do_tiao", "jump");
}

int do_use(string arg)
{
        object me = this_player();

        if (! arg || arg == "" ) 
                return 0;

        if (! present("fire", me))
                return 0;

        if (this_object()->query("mark/light"))
                return notify_fail("���Ѿ����Ż����ˡ�\n");

        if (arg == "fire")
        {
                message_sort(HIR "\n$N" HIR "ȡ������һ�Σ������ֻ����"
                             "��ʯ�ڶ��Ǿ�Ө���񣬵��·��ż������Σ�����"
                             "������һ�������Ӿ�Ȼ���Ǽ�����̣�ԭ��ɽ��"
                             "�ܱգ����ܷ��֣����Զ������²������á�\n\n"
                             NOR, me);

                set("long", @LONG
����΢���Ļ�⣬ֻ������ʯ��(wall)���Ǿ�Ө���񣬵�
�·��ż���ľ�����Ρ�������������һ�������Ӿ�Ȼ���Ǽ���
��̣�ԭ��ɽ���ܱգ����ܷ��֣����Զ������²������á�

LONG);

                set("item_desc", ([
                        "wall" : WHT "ֻ��ʯ������һ���ѷ죬�Ӻ��������"
                                 "����Ʈ����������硣\n" NOR, 
                ]));
                add("mark/light", me->query("id"));
                return 1;
       }
}

int do_tiao(string arg)
{
        object ob, me = this_player();

        if (! this_object()->query("mark/light"))
                return notify_fail("����һƬ��ڣ������̽���巽��\n");

        if (! arg || arg != "down")
                return notify_fail("��Ҫ��������\n");

        message_vision(HIY "\n$N" HIY "ԥ��һ�£�����������������ȥ��\n\n" NOR, me);

        // �ж���˭��ȼ�Ļ��ۣ�����ֻ�����������ȥ����ָ��ڰ���
        if (this_object()->query("mark/light") == me->query("id"))
        {
                delete("mark/light");
                set("long", "ɽ�������ֲ�����ָ���ڳ�������ôҲ�Ʋ�����\n");

                message("vision", HIR + me->name() + HIR "�������Ż���������ȥ"
                        "�������漴����һƬ��ڡ�\n" NOR, environment(me), ({me}));
        }

        if ((int)me->query_skill("dodge", 1) < 150 )
        {
                me->move(__DIR__"yongdao2");
                me->receive_wound("qi", 300);
                me->unconcious();
                message("vision", HIR "\nͻȻ���á��项��һ����ֻ��һ���˴���"
                                  "���ɽ����׹������������׳�ۡ�\n" NOR,
                                  environment(me), ({me}));
        } else
        {
                me->move(__DIR__"yongdao2");
                message("vision", HIY + me->name() + HIY "����������������\n" NOR,
                                  environment(me), ({me}));
        }
        return 1;
}
