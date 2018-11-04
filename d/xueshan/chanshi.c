#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������ɮ���Ų��������ĵط������һ���������˿��˾�
�뵽������¡������ŵ�ǽ���и���ͭ����(lunpan)�������
��Щϣ��ŹֵĻ��ƣ���֪��ʲô��˼��
LONG);
        set("no_fight", 1);
        set("sleep_room", 1);
        set("no_steal", 1);

        set("exits", ([
                "east"  : __DIR__"tiantai",
                "south" : __DIR__"houdian",
        ]));

        set("item_desc", ([
                "lunpan": YEL "\n����һ���ɻ�ͭ�����Ĵ����̣���������"
                          "�������ϣ��ŹֵĻ�\n�ƣ�ȫ�Ǻͷ�ˮ�йء�"
                          "�����������ת(turn)������\n" NOR,
        ]));

        setup();
}

void init()
{
        add_action("do_turn", "turn");
}

int do_turn(string arg)
{
        object me = this_player();

        if (! arg || arg != "lunpan")
                return notify_fail("��Ҫת��ʲô��\n");

        message_vision(HIY "\n$N" HIY "ʹ��ת�����̣������Ȼ������������"
                       "��һ�����ڡ�\n\n" NOR, me);
        set("exits/down", __DIR__"midao");
        remove_call_out("close");
        call_out("close", 8, this_object());

        return 1;
}

void close(object room)
{
        message("vision", WHT "�����Ȼ��������������ԭ�أ����ܵ�����ڵ�"
                          "ס�ˡ�\n" NOR, room);
        room->delete("exits/down");
}
