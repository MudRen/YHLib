inherit ROOM;
#include <ansi.h> 

void create()
{
        set("short","���¾�");
        set("long",@LONG
���ǰ����ڵ����ң��Ҿ����Σ�����������ν��̻Իͣ���
�������������ڰ������Ѳ�֪ȥ��ֻʣ����һ����ң�������
����ҭҭ�ؿޡ�
LONG);
        set("exits",([
            "south"  : __DIR__"book",   
        ]));
        set("objects", ([  
                __DIR__"npc/yaoniang" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

