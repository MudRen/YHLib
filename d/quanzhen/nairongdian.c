inherit ROOM;

void create()
{
        set("short", "���ݵ�");
        set("long", @LONG
�����Ǵ����ԱߵĲ�Ҳ�ǽӴ���Ҫ���˵ĵط����
��ֻ�ڷ���һ�����Ӻͼ������ӡ����ϰڷ���һ����ɽ����
���辰��ǽ���Ϲ���һЩ�ֻ���
LONG);
        set("exits", ([
                "south" : __DIR__"qingjing",
                "west" : __DIR__"piandian",
                "north" : __DIR__"datang3",
        ]));
        set("objects", ([
                CLASS_D("quanzhen") + "/cheng" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
