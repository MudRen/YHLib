inherit ROOM;

void create()
{
        set("short", "�ܵ�");
        set("long", @LONG
�����Ƕ��һ����������һ����խ�İ�������ɭ���£���
�������˻ҳ���������������Ҳ��֪��ͨ���δ���
LONG);
        set("exits", ([
                "up"    : __DIR__"hcadadian",
                "north" : __DIR__"midao2",
        ]));
        setup();
        replace_program(ROOM);
}