inherit ROOM;

void create()
{
        set("short", "�ܵ�");
        set("long", @LONG
�����Ƕ��һ����������һ����խ�İ�������ɭ���£���
�������˻ҳ���������������Ҳ��֪��ͨ���δ���
LONG);
        set("exits", ([
                "south" : __DIR__"midao4",
                "up"    : "/d/city3/qingyanggong",
        ]));
        setup();
        replace_program(ROOM);
}