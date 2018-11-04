#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�͵�");
        set("long", @LONG
����һ�Ҽ�Ǯ�����Ŀ�ջ������ǳ���¡������οͶ�ѡ
��������ţ��������������������صķ������顣��С����
������æ������ת���Ӵ�����ǻ�����Ŀ��ˡ��͵�����˴Ӳ�
¶�档ǽ�Ϲ���һ�����ӡ�
LONG);
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
                __DIR__"npc/xiaoer1" : 1,
        ]));

        set("exits", ([
                "north" : __DIR__"majiu",
                "south" : __DIR__"dongjie",
                "up"    : __DIR__"kedian2",
        ]));
        setup();
}

int valid_leave(object me, string dir)
{

        if (! me->query_temp("rent_paid") && dir == "up")
                return notify_fail(CYN "��С��һ�µ���¥��ǰ������һ������"
                                   "���ţ����ס����\n" NOR);

        if (me->query_temp("rent_paid") && dir == "south")
                return notify_fail(CYN "��С���ܵ��ű���ס���͹��Ѿ�������"
                                   "�ӣ����᲻ס��������أ�\n" NOR);

        return ::valid_leave(me, dir);
}
