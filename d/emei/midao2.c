inherit ROOM;

void create()
{
        set("short", "�ܵ�");
        set("long", @LONG
�����Ƕ��һ����������һ����խ�İ�������ɭ���£���
�������˻ҳ���������������Ҳ��֪��ͨ���δ���
LONG);
        set("exits", ([
                "south" : __DIR__"midao",
                "north" : __DIR__"midao3",
        ]));
        setup();
        replace_program(ROOM);
}