inherit ROOM;
#include <ansi.h> 

void create()
{
        set("short", "����Ԩ��");
        set("long", @LONG
���˷����£���ͷ�������������ȣ��������������뻹�е�
���£����Ͼ������ˡ���ǰ���������������ˣ����������д�˵
�����ǣ����ڳ���������ǰ�ˣ��Ͽ��ȥ�����ɡ�  
LONG);
        set("outdoors", "lingxiao");
        set("exits", ([
            	"north" : __DIR__"shanya",
            	"south" : __DIR__"bingqiao",
        ]));
        setup();
        replace_program(ROOM);
}


