inherit ROOM;
 
void create()
{
        set("short", "��԰С��");
        set("long",@LONG
����������е�С��԰���������ֻ���òݵ������ƺ�
�������ݣ����ߺ�������һ����԰��
LONG);
        set("exits", ([
            	"west"  : __DIR__"chufang1",
            	"east"  : __DIR__"hua1",
             	"north" :__DIR__"dating1",
             	"south" :__DIR__"grass1",
        ]));
        set("objects", ([
                __DIR__"npc/shinu" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
