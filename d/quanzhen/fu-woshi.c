#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǻ�Ա������ң��������������һ�������ӡ�����
�����ŵ��Ű��ɹ����Ĵ󴲣���ͷ�и�����(drawer)��������
˿�¶У����Ľ����������������
LONG);
        set("sleep_room",1);
        set("exits", ([
                "north" : __DIR__"fu-houyuan",
        ]));
        set("objects", ([
                __DIR__"npc/yuanwai" : 1,
        ]));
        set("item_desc", ([
                "drawer": RED "һ�����룬���������(pull)������"
                          "������в��ٽ����鱦Ŷ��\n" NOR
        ]));

        setup();
}

void init()
{
        add_action("do_pull","pull");
}

int do_pull(string arg)
{
        object me = this_player();

        if (! arg || arg != "drawer")
                return notify_fail("��Ҫ����ʲô��\n");

        message_vision(HIY "\n$N" HIY "�ѳ�����������û���ü���������ʲô��"
                       "����ֻ���ô���֨\n֨�������Զ������߷ֿ����ֳ�һ����"
                       "����Ķ��ڡ�\n" NOR, this_player());

        set("exits/down", __DIR__"fu-midao");
        remove_call_out("close");
        call_out("close", 5, this_object());

        return 1;
}

void close(object room)
{
        message("vision", WHT "�����ֺ����������Ѷ��ڷ�ס�ˡ�\n" NOR, room);
        room->delete("exits/down");
}
