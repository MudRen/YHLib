inherit ROOM;

void create()
{
        set("short", "�Ҷ�");
        set("long", @LONG
������һ�����Ҷ����ڰ���ɽ����ĵ��������¾�������
������γɵġ������������ۣ�Ҳ��֪���쵽�˺δ���
LONG);
        set("exits", ([
                "enter"     : __DIR__"cave1",
                "southdown" : __DIR__"zhulin",
        ]));
        set("objects", ([
                "/clone/beast/mangshe" : 1,
        ]));
        set("outdoors", "baituo");
        setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "enter"
           && objectp(present("mang she", environment(me))))
                        return notify_fail("���������Ҷ��ڣ���·���˸���ʵ��\n");

        return ::valid_leave(me, dir);
}
