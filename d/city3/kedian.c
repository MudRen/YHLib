#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
��������ȫ�������Ŀ͵꣬����ǳ���¡������οͶ�
ѡ��������ţ��������������������صķ������顣��С��
��������æ������ת�����صĴ�ζ�ٻ�����ʵ������˳������
�ǳɶ������ٰ�Ŀ�ջ���Ӵ��Ÿ����봨�Ĺٲ����ˡ�ǽ�Ϲ�
��һ������(paizi)��
LONG );
        set("no_fight", 1);
        set("valid_startroom", 1);
        set("no_sleep_room",1);

        set("item_desc", ([
                "paizi" : WHT "\n\n        ����������������������������������\n"
                              "        ��                              ��\n"
                              "        ��    " NOR + HIW "¥���ŷ���ÿҹʮ��������" NOR + WHT "  ��\n"
                              "        ��                              ��\n"
                              "        ����������������������������������\n\n\n" NOR,
        ]));
        set("objects", ([
                __DIR__"npc/xiaoer" : 1,
        ]));
        set("exits", ([
                "northwest" : __DIR__"southroad1",
                "up"        : __DIR__"kedian2",
                "east"      : __DIR__"majiu",
        ]));
        setup();
        "/clone/board/kedian3_b"->foo();
}

int valid_leave(object me, string dir)
{

        if (! me->query_temp("rent_paid") && dir == "up")
                return notify_fail(CYN "��С��һ�µ���¥��ǰ������һ���������ţ����ס����\n" NOR);

        if (me->query_temp("rent_paid") && dir == "west")
                return notify_fail(CYN "��С���ܵ��ű���ס���͹��Ѿ��������ӣ����᲻ס��������أ�\n" NOR);

        return ::valid_leave(me, dir);
}
