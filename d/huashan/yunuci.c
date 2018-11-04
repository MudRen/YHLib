#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��Ů��");
        set("long", @LONG
��Ů���﹩��ĵ�������λ��Ů������಻ͬ��˵�����������ܿ���
��ֻһ������ʯ�����д�ʯ����һ�����ݣ�������ˮ��̣�������Ů
��ϴ���裬��ˮ���겻�ɡ���Ů�������һ��ɽ��(cliff)�����Ƕ��͡�
LONG
        );
        set("outdoors", "huashan");
        set("exits", ([
                "east" : __DIR__"yunu",
        ]));
        set("item_desc", ([
                "cliff" : "��Ů���µ�ɽ�º��Ƕ��ͣ��ƺ�������һ��С·��\n",
        ]));

        set("resource/water", 1);
        setup();
}

void init()
{
        add_action("do_jump", "jump");
}

int do_jump(string arg)
{
        object me = this_player();
        int n = me->query("dex");

        if (! arg || arg != "cliff")
        {
                write("���������������\n");
                return 1;
        }

        message_vision( HIY "$N" HIY "������һ������������ɽ����ȥ��\n" NOR, me);

        if (n < 30)
        {
                message_vision( HIR "���$N" HIR "�ҽ���һ����������ɽ��"
                                "��\n" NOR, this_player());

                me->move(__DIR__"kuihua_2");
                me->unconcious();

                message("vision", HIR "ֻ��" + me->name() + HIR "һ���ҽ�"
                                  "���������ɽ�������ص�ˤ��������\n" NOR,
                                  environment(me), ({me}) );
        } else
        {
                message_vision( HIC "ֻ��$N" HIC "���ý�������һ�ݣ�ƮȻ��"
                                "���µס�\n" NOR, this_player());

                me->move(__DIR__"kuihua_2");

                message("vision", HIC "ֻ��" + me->name() + HIC "�������ɽ������"
                                  "������������\n", environment(me), ({me}) );
        }
        return 1;
}
