inherit ROOM;

void create()
{
        set("short",  "��ʯ·" );
        set("long", @LONG
һ����ʯ�������ʯ�̳ɣ�ƽ̹������̧ͷһ����ǰ���
���������ɼ���
LONG);
        set("outdoors", "kunming");
        set("exits", ([
                "west" : __DIR__"dongmen", 
                "east"  :__DIR__"qingshilu1",
        ]));
        setup();
        replace_program(ROOM);
}
