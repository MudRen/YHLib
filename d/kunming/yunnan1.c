inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
�����ƹ��ԭ��������Ϊ�˺�ɫ��������ø����£�����
��ȥ��ֻ����Χ�������ԭʼɭ�ֲ����߼ʣ����ʱ�����ĸ�
־Զ��һ�ɺ���ӿ����������Ҫ��һ������ҵ��
LONG);
        set("outdoors", "kunming");
        set("exits", ([
                "south" : __DIR__"yunnan2", 
                "northeast"  :__DIR__"yunnan",
        ]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
