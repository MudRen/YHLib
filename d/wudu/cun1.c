inherit ROOM;

void create()
{
        set("short", "С���");
        set("long", @LONG
�������һ����ߵ�һ��С�壬����м���ũ�ҵ�С�����ڴ�����
����ˣ��ԶԶ���������ƴ��̣�æµ��һ������ǿ�ʼ�����ˡ� 
LONG);
        set("outdoors", "wudujiao");

        set("exits", ([
                "east" : __DIR__"cun2",
                "west" : __DIR__"jiang2",
        ]));
        set("objects", ([
                 __DIR__"npc/kid": 3,
        ]));
    
        setup();
}
