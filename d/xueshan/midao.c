inherit ROOM;

void create()
{
        set("short", "�ܵ�");
        set("long", @LONG
���������������һ����խ�İ�������ɭ���£���������
�˻ҳ���������������Ҳ��֪��ͨ���δ���
LONG);
        set("exits", ([
                "north" : __DIR__"mishi",
                "up"    : __DIR__"chanshi",
        ]));
        setup();
        replace_program(ROOM);
}
