#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ɽɽ·");
        set("long", @LONG
��������ɽ��´��ɽ���ɽ�ϴ����������ɪɪ������·
����һƬ��ԭ������һ���(valley)��ס����ɽ��·��
LONG );
        set("exits", ([
                "northup" : __DIR__"xxroad4",
                "eastdown" : __DIR__"xxh1",
        ]));
        set("item_desc", ([
                "valley" : WHT "\n��������ɶ����֪���ܲ�������ȥ��\n" NOR,
        ]));
        set("objects", ([
                CLASS_D("xingxiu") + "/azi" : 1,
        ]));
        set("outdoors", "xingxiu");
        setup();
}

void init()
{
        add_action("do_jump", "jump");
        add_action("do_jump", "tiao");
}

int do_jump(string arg)
{
        object me;
        me = this_player();

        if (! arg || arg != "valley")
                return notify_fail("��Ҫ��������\n");

        message_vision(HIY "\n$N" HIY "ԥ��һ�£��������������Ŷ����ɽ�����˹�"
                       "ȥ��\n\n" NOR, me);

        if ((int)me->query_skill("dodge", 1) < 150 )
        {
                me->move(__DIR__"shanjiao");
                me->receive_wound("qi", 300);
                me->unconcious();
                message("vision", HIR "\nͻȻ���á��项��һ����ֻ��һ���˴�����"
                                  "��ɽ����׹������������׳�ۡ�\n" NOR,
                                  environment(me), ({me}));
        } else
        {
                me->move(__DIR__"tianroad4");
                message("vision", HIY "\nֻ��" + me->name() + HIY "�Ӷ����ɽ��"
                                  "�����˹�����\n" NOR, environment(me), ({me}));
        }
        return 1;
}
