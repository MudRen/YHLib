inherit ROOM; 

#include <ansi.h>;

void create()
{
    set("short", "Ϸ÷ͤ");
    set("long", @LONG 
�����������ǵ�Ϸ÷ͤ������������������ƽʱ��ϲ������
�ط��������︩�Ⱥɽ�����󵱷磬ֻ�����ｭɽ���������һ
���������Ͽ���һ��ʫ(poem)���ǰ���ү�Ӿƺ��������̽���
����������ȴ˵����ү����ƽ���Ǻ���������˵���Լ����Լ���
�ͣ���Ҳû����ֱ�����ڰ���ү����ǰ�����䡣
LONG);
    	set("exits", ([
        	"west" : __DIR__"meiroad3",
    	])); 
        set("objects", ([ 
                __DIR__"obj/ban" : 3,
        ])); 
        set("item_desc", ([
        	"poem" : HIR "\n\n          �̰Ѹ���������ǳ�õͳ���\n\n" NOR,
        ]) );
        setup();
    	set("outdoors", "lingxiao");
    	set("no_clean_up", 0);
    	setup();
        replace_program(ROOM);
}

