inherit ROOM;
#include <ansi.h> 

void create()
{
        set("short","����");
        set("long",@LONG 
����һ�䰲���ľ��ң��������ǵ��������ӹ����ӵķ��䡣
���Ϸ���һ����ѩ�ķ�����ǽ�Ϲ���һ��������������Ӵ�
�������룬����ǽ�ϣ�ӳ��һ�������ｭɽͼ��������ΰ��
LONG);
        set("exits", ([
            "south"  : __DIR__"zoulang1", 
        ]));
        set("objects", ([  
                CLASS_D("lingxiao") + "/gengwanzhong" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

