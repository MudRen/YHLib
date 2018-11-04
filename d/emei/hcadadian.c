#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���۱���");
        set("long", @LONG
���Ƕ���ɽ�����ֵĴ��۱�����й�����������������
Ⱥ����Сʦ̫���ڵ����о��������е�С��ͨ���������
�����ɵ��������������ʦ̫�����ĵط���
LONG);
        set("exits", ([
                "north" : __DIR__"hcaguangchang", 
                "south" : __DIR__"hcahoudian", 
        ]));
        set("objects", ([
                __DIR__"obj/xiang" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_move", "move");
}

int do_move(string arg)
{
        object me = this_player();

        if (! arg || arg != "xiang")
                return notify_fail("��Ҫ�ƶ�ʲô��\n");

        if (query("exits/down"))
                return notify_fail("�����Ѿ����ƿ��ˡ�\n");

        message_vision(HIC "\n$N" HIC "��һ�ƶ�" NOR + YEL "����������"
                       HIC "��������ȴ�Լ���һ���ƿ��������ֳ�һ������"
                       "��\n\n" NOR, me);
        set("exits/down", __DIR__"midao");
        remove_call_out("close");
        call_out("close", 8, this_object());

        return 1;
}

void close(object room)
{
        message("vision", WHT "��Ȼֻ������������������" YEL "����������"
                          WHT "����ԭ�أ����ܵ���ס�ˡ�\n" NOR, room);
        room->delete("exits/down");
}
