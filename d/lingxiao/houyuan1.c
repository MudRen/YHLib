inherit ROOM;

#include <ansi.h> 

void create()
{
        set("short","��԰");
        set("long",@LONG 
�����������ɵĺ�԰��С����ˮ�������͸󡣲�̨�ʴ䣬��
���������ɸ������������޵ء���������ѩɽ֮�ϣ���������ů
�紺�ĵط���ʵ�������Ҳ�ѹֵ���������ʦҪ�����ڴ��ˡ���
���е�һ����ɽ�ϣ�һ����Ȫ��������������������������á�
LONG);
        set("outdoors", "lingxiao");
        set("exits", ([
            "north"  : __DIR__"houyuan2",  
            "south"  : __DIR__"zhongting", 
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

