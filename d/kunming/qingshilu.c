inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
����ʯ�֣��͵��������Ĺٵ�����ʯ�̳ɣ�ƽ̹��������
ȥ��Զ���������ˡ�
LONG);
        set("outdoors", "kunming");

        set("exits", ([
                "west" : __DIR__"qingshilu1", 
                "east" : __DIR__"shilin2",
        ]));
        setup();
        replace_program(ROOM);
}
