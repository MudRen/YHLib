#include <ansi.h>
inherit ROOM;
inherit __DIR__"tsr_room_dugu-jiujian.c";

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
����һ�����ʯ�ң�ֻ�����ܿտ��ޱȣ���Զ����һ��
��״���ص�ʯ����desk����
LONG);
        set("exits", ([
                "out" : __DIR__"s",
        ]));
        set("room_id", "number/lockroom6");
        set("item_desc", ([
             "desk" : NOR + WHT "һ����״���ص�ʯ�����ƺ�������ʲô���أ�\n" NOR,
        ]));
        set("no_clean_up", 0);
        setup();
}



