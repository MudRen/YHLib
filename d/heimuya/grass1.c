inherit ROOM;
 
void create()
{
        set("short", "�ݵ�");
        set("long",@LONG
����������е�С��԰���������ֻ���òݵ������ƺ�
�������ݣ��ϱ߲�Զ���Ƿ����õĴ����ˡ�
LONG );
        set("exits", ([
            	"south"    : __DIR__"fen0", 
            	"north"    :__DIR__"grass2",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "heimuya");
        setup();
        replace_program(ROOM);
}
