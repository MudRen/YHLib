#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", NOR + WHT "���κ��š�" NOR);
        set("long", NOR + WHT @LONG

                    ��         ��         ��

    �����������������ͨ�����κ��š����������ⳤ����ʯ�ƹ�����
�棬����������޿�����ش������Բ���������ŵ���һ��վ��һ��ţ
ͷ�������������ϸ�Ĳ鿴�Ź��������ꡣ


LONG NOR );
        set("exits", ([
                "north" : __DIR__"hell1",
                "south" : __DIR__"qiao1",
        ]));
        set("objects", ([
                __DIR__"npc/niutou":1,
                __DIR__"npc/ghost":1,
        ]));
        set("item_desc", ([
                "north": HIW "\n�κ��ŵ���һ�˱����������֣��·�û��"
                         "��ͷ����ʲô�������塣\n" NOR
        ]));

        set("no_sleep_room", 1);

        setup();
}
int valid_leave(object me, string dir)
{
        int i;
        object ob;
        me = this_player();
        if (dir == "north")
        {
                if (objectp(present("niu tou", environment(me))))
                        return notify_fail(CYN "ţͷ������һ�ۣ��ȵ����㻹����"
                                           "��ȥ�������������ʲô���֣�\n" NOR);
        }
        return ::valid_leave(me, dir);
}