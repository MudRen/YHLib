inherit ROOM;

void create()
{
        set("short", "С������");
        set("long", @LONG
������һ��СС��ʯ�ң��ط���խ��ȴ���˼���ľ�ˣ���
֪���������ڲ��»�������ʲôԭ�򡣵�����Щ���ң�����
���Ǿ�����ɨ��
LONG);
        set("exits", ([
                "north" : __DIR__"liangong2",
        ]));
        set("for_family", "��Ĺ��");
        set("objects", ([
                "/kungfu/class/gumu/li"  :  1,
        ]));
        setup();
        replace_program(ROOM);
}

