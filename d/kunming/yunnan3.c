inherit ROOM;

void create()
{
        set("short", "ԭʼɭ��");
        set("long", @LONG
���߽�ԭʼɭ�֣�ֻ����Χ����ããȫ�ǲ������������
���գ����ܹ��ߺܰ����ֲ��嶫������������˭������������
��ȥ�ˡ��Һõ�����������ʱ��������һ��·�����򣬾���
�������޳Ե�������ҲҪ�����ζ�����
LONG);
        set("outdoors", "kunming");

        set("exits", ([
                "east" : __DIR__"yunnan2", 
                "south"  :__DIR__"yunnan4",
        ]));
        setup();
        replace_program(ROOM);
}
