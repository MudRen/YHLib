#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�ܷ�ͤ");
        set("long", @LONG
������һ����԰�е�Сͤ�ӣ�������������ɫ���㡣ͤ��
������������ͭ��¯(lu)��¯����ð���������̣�Ҳ��֪��ȼ
��ʲô��������ζ��Ϊ�̱ǡ�
LONG);
        set("exits", ([
                "west" : __DIR__"huayuan2",
                "north" : __DIR__"huating1",
        ]));

        set("item_desc", ([
                "lu" : YEL "\n����һ����ͭ��¯��ģ����Ϊ�žɣ���¯��"
                       "Χ�ƺ����ƶ����ĺۼ���\n" NOR,
        ]));

        setup();
}

void init()
{
        add_action("do_move", "move");
}

int do_move(string arg)
{
        object me = this_player();

        if (! arg || arg != "lu")
                return notify_fail("��Ҫ�ƶ�ʲô��\n");

        if (query("exits/down"))
                return notify_fail("��¯�Ѿ����ƿ��ˡ�\n");

        message_vision(HIY "\n$N" HIY "��һ�ƶ���¯����¯ȴ�Լ�"
                       "��һ���ƿ��������Ȼ�ֳ�һ�����ڡ�\n\n"
                       NOR, me);
        set("exits/down", __DIR__"midao");
        remove_call_out("close");
        call_out("close", 8, this_object());

        return 1;
}

void close(object room)
{
        message("vision", WHT "��Ȼֻ��������������������¯����"
                          "ԭ�أ����ܵ���ס�ˡ�\n" NOR, room);
        room->delete("exits/down");
}
