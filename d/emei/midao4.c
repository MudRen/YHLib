inherit ROOM;

void create()
{
        set("short", "�ܵ�");
        set("long", @LONG
�����Ƕ��һ����������һ����խ�İ�������ɭ���£���
�������˻ҳ���������������Ҳ��֪��ͨ���δ���
LONG);
        set("exits", ([
                "west"  : __DIR__"midao3",
                "north" : __DIR__"midao5",
        ]));
        setup();
        replace_program(ROOM);
}