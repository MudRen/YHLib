inherit ROOM;
#include <ansi.h> 

void create()
{
        set("short", "����");
        set("long", @LONG 
�����������ķ��䡣��λ�����У�������Ϊ���Զ��ǣ�����
˵�����ǵ�����ʦ��ȥ֮ʱ���������������ڣ���������������
֮ʱ������Ѷ�����������֮λ��Ϊ������֮��ⷿ���ڰ���
���飬�ӡ����ӱ���������ʷ�ǡ���������Ȩı����֮�顣
LONG);
        set("exits",([
            	"south"  : __DIR__"zoulang3", 
        ]));
        set("objects", ([  
                __DIR__"npc/liao" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

