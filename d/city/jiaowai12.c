#include <room.h>
inherit ROOM;

void create()
{
    	set("short", "����");
    	set("long", @LONG
���ݽ����ï�����֣���ɭ�ɲ���̧ͷ�������ա�����Ҳ
�����������������ĵط��������߳��ε����
LONG);
        set("outdoors", "city");
    	set("exits", ([
        	"south" : __DIR__"jiaowai10",
        	"west"  : __DIR__"jiaowai13",
    	]));
    	set("objects", ([
        	"/clone/beast/dushe" : 2,
        	__DIR__"obj/shuzhi": 1,
    	]));
    	setup();
    	replace_program(ROOM);
}
