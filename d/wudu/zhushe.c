inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ�����Ӵ�ɵķ��ӣ���Ȼ��ª��ȴ��������ʰ�ĸɸɾ�����
һ�������ڽ���ò���ŵ���ʿ�����ڰ����п������������Ų�����
��̧��ͷ����
LONG);

        set("exits", ([
                "north" : __DIR__"caoping",
        ]));
        set("objects", ([
                __DIR__"npc/zhuge": 1,
        ]));

        setup();
        replace_program(ROOM);
}
