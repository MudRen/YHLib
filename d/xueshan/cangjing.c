inherit ROOM;

void create()
{
        set("short", "�ؾ���");
        set("long", @LONG
�����Ǵ����µĲؾ�֮����������������ܶ������ĵ伮��
������һ����Ҳ��������
LONG);
        set("exits", ([
                "south" : __DIR__"dating",
        ]));
        setup();
        replace_program(ROOM);
}
