inherit ROOM;

void create()
{
        set("short", "�ݴ�");
        set("long", @LONG
�������Ҳݴԡ������������֡��������涼�������ߵ���
�ݣ������߳�û��
LONG);
        set("exits", ([
                "west"  : __FILE__,
                "north" : __DIR__"zhulin",
                "east"  : __DIR__"cao1",
                "south" : __DIR__"cao1",
        ]));

        set("objects", ([
                "/clone/beast/qingshe" : random(2),
                "/clone/beast/jinshe"  : random(2),
                "/clone/beast/dushe"   : 1,
        ]));

        set("quarrys", ([
                "caihuashe"  : 100000,
                "dushe"      : 50000,
                "jinshe"     : 40000,
                "qingshe"    : 40000,
                "yanjingshe" : 5000,
                "mangshe"    : 3000,
        ]));

        set("outdoors", "baituo");
        setup();
        replace_program(ROOM);
}
