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
                "north" : __DIR__"dadao2",
                "westdown" : __DIR__"xianchou",
        ]));
        set("objects",([
                "/clone/quarry/song" : 1,
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
