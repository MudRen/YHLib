inherit ROOM;

void create()
{
        set("short", "�һ���");
        set("long", @LONG
���Ǽ�������᷿�����Ŵ������ţ����ߺܻ谵�������
�����ֻ���м����һ����ʰ����������Ĵ󴲣����ž���
����˯����
LONG);
        set("exits", ([
                "west" : __DIR__"siguoshi",
        ]));
        set("sleep_room", 1);
        set("no_fight", 1);
        setup();
}