inherit ROOM;

void create()
{
        set("short", "ƫ��");
        set("long", @LONG
�����Ǵ����ԱߵĲ�����Ҳ�ǽӴ���Ҫ���˵ĵط�������
��ֻ�ڷ���һ�����Ӻͼ������ӡ����ϰڷ���һ����ɽ����
���辰��ǽ���Ϲ���һЩ�ֻ���
LONG);
        set("exits", ([
                "east" : __DIR__"nairongdian",
                "west" : __DIR__"xianzhentang",
                "north" : __DIR__"datang2",
                "south" : __DIR__"guangning",
        ]));
        set("objects", ([
                CLASS_D("quanzhen") + "/shen" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
