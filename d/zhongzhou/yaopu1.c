inherit ROOM;

void create()
{
        set("short", "ҩ����Ժ");
        set("long", @LONG
�������ҩ����Ժ����һ�߽����;���һ�����ˡ�ֻ��ʮ
��ֻ¯�Ӷ��ڰ�ҩ���м���ҩ�̵Ļ����æµ�š���Ҫ��ҩ��
����Ҫ����ҩ���ѷŽ�ҩ���
LONG);
        set("exits", ([
                "north" : __DIR__"yaopu",
                
        ]));

        setup();
        replace_program(ROOM);
}
