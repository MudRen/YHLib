inherit ROOM;
#include <room.h>

void create()
{
    	set("short", "���");
    	set("long", @LONG
���ߵ���ڣ�ֻ�������Ҳ�������Ǻ��ǣ�����ɢ��
��һ�أ��������ձ����й�һ����ս�����е��µ����Ǵ��С
С��������������ǹ��ꪶ��У�ֻ����״���أ�������ϰ����
��Ȼ��ͬ������ǰ����һ��ʮ�ֹ⻬��ʯ�塣
LONG);
        set("objects", ([
                __DIR__"obj/yufu" : random(3),
                __DIR__"obj/yudao" : random(3),
                __DIR__"obj/yujian" : random(3),
        	__DIR__"obj/skeleton" : random(5) + 3,
        	__DIR__"obj/skeleton1" : 1,
	]));
    	set("exits", ([ 
        	"west" : __DIR__"yongdao4",
        	"north" : __DIR__"diantang",
	]));
    	setup();
}
