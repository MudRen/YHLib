inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����������ڵͰ��Ĺ������棬���ܵ������ǻҳ���֩��
������һ̧ͷ�ͻ��������档�������ӵ����ܶ�������Ĳ���
��ס�ˣ��㿴������������������Ҳ���ֲ����㡣 
LONG);

        set("exits", ([
                "out" : __DIR__"minju7",
        ]));
        setup();
        replace_program(ROOM);
}
