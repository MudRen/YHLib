inherit ROOM;

void create()
{
        set("short", "ɹ�ȳ�");
        set("long", @LONG
�����Ǵ�ׯ���ĵ�ɹ�ȳ����ط����󣬲�������Ҳ������
���˼ң��ֵĹ���Ҳ��ɹ�ˡ����������ջ�ļ��ڣ��ȳ��ж�
���˹��ӣ�������Ůͯ�����ڳ������֣���ʱ������һ������
�໥��ȥ��
LONG);
        set("outdoors", "wugong");
        set("exits", ([
                "southeast" : __DIR__"xiaocun",
                "north" : __DIR__"cunzhangjia",
                "northwest" : __DIR__"minju3",
                "southwest" : __DIR__"minju4",
        ]));
        set("objects", ([
                __DIR__"npc/boy" : 2,
                __DIR__"npc/girl" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
