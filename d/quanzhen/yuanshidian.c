inherit ROOM;

void create()
{
        set("short", "Ԫʼ��");
        set("long", @LONG
�����ǹ���Ԫʼ����Ĵ������������ƣ�����������
Ԫʼ����Ľ����Ա߻����ż�λ������̫�ҡ����������
�ӡ�����ӵȵȵ���������һ�����ɻ����������衣
LONG);
        set("exits", ([
                "south" : __DIR__"laojundian",
        ]));
        set("objects", ([
                CLASS_D("quanzhen") + "/qi" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
