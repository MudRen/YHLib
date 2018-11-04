#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���Ӿ�");
        set("long", @LONG
������ȫ����Ӿ�ס�ķ��䡣����ܴ����������һ��
�ŵĴ������ϱ��춼�۵��ú����룬�������˶�û�У�Ҳ����
�еĵ��Ӷ�ȥ����ȥ�ˡ���ǽ�ĵط��и�����(cabinet)��
LONG);
        set("sleep_room",1);
        set("exits", ([
                "north" : __DIR__"jingxiushi",
        ]));
        set("item_desc", ([
                "cabinet": RED "����һ����ľ�ǹ�Ҳ��"
                           "�Ƕѷ������õġ�\n" NOR
        ]));
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_pull","pull");
}

int do_pull(string arg)
{
        object me = this_player();

        if (! arg || arg != "cabinet")
                return notify_fail("��Ҫ����ʲô��\n");

        message_vision(HIY "\n$N" HIY "ʹ���ѹ����������ֳ�һ�����ڡ�"
                       "ԭ�����������ҵ���ڡ�\n\n" NOR, me);
        set("exits/down", __DIR__"mishi");
        remove_call_out("close");
        call_out("close", 8, this_object());

        return 1;
}

void close(object room)
{
        message("vision", WHT "������֨֨�ػص�ԭ�أ�����ڵ�ס�ˡ�\n"
                          NOR, room);
        room->delete("exits/down");
}
