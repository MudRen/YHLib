inherit ROOM;
#include <ansi.h> 

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǿ�����ķ��䡣������ϲ���ռ������������ıڶ���
��������ɫɫ�ĵ����������������󽣣�Ӧ�о��С����߻�����
һ����ֵĶ�������˵��ǰ����������ķ����͸����Ļ�ǹ����
˵��ү����������һ������������ڴ�������һ���¡�
LONG);
        set("exits", ([
            	"south"  : __DIR__"zoulang2", 
        ]));
        set("objects", ([  
                CLASS_D("lingxiao") + "/kewanjun" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

