inherit ROOM;

void create()
{
        set("short", "��ѻ��");
        set("long", @LONG
����һ�����ļ��룬����������һ���������������ƶ��
ȽȽ������ɽ�����������Ϯ��������ֻ��ѻ�������Ƽʣ���
�׷�����ε����ۡ�
LONG);
        set("objects", ([
                "/clone/quarry/niao3" : 3,
        ]));
        set("exits", ([
                "northdown": __DIR__"langmeiyuan",
                "southup"  : __DIR__"sanlaofeng",
        ]));
        set("outdoors", "wudang");
        setup();
        replace_program(ROOM);
}
