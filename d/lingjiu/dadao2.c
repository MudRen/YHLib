inherit ROOM;

void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
��������ʯ�̳ɵĿ������ÿ����ʯ���ǳ�Լ�˳ߣ���
Լ���ߣ��������롣�����������де������֣���ʱ���Կ���
��ֻ����ı�������Ծ���������������ȥ��һ���޴��ʯ
��ΡȻ������
LONG);
        set("outdoors", "lingjiu");

        set("exits", ([
                "north" : __DIR__"damen",
                "south" : __DIR__"dadao1",
        ]));
        set("objects", ([
                "/clone/quarry/song" : 2,
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
