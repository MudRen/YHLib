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
        	"south" : __DIR__"jiaowai11",
        	"east"  : __DIR__"jiaowai12",
    	]));
    	setup();
    	replace_program(ROOM);
}

