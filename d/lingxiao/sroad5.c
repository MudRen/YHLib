inherit ROOM;  
#include <ansi.h> 

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
Խ�����ߣ�����������˪ѩ����׷׶��¡���ĿԶ����ֻ��
����ѩ�ף����ﾧӨ����Զ���ƺ��и�������ɽȪ�ٲ����������
��������������ʻ��������ޣ����㲻�ɵüӿ�Ų���·�Խ���
��һ�����������������£�����������ʱ������������֮ʱҲ
������Ϊ����ʹ�á�
LONG);
        set("outdoors", "lingxiao");
        set("exits", ([
            	"southdown"  : __DIR__"sroad4",
            	"north"  : __DIR__"sroad6",
        ]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
        set("no_clean_up", 0);
	set("ice_count", 5);
        setup();
        replace_program(ROOM);
} 
