#include <room.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���ݽ�������֣���֦ͦ�Σ���ľ��б���ּ�С��������
��Զ�����в������֣�������ת��ʹ���ʱ���⾡����������
�˺ܶ���֦ʯ�顣
LONG);
        set("outdoors", "city");
    	set("exits", ([
        	"east" : __DIR__"jiaowai5",
        	"west" : __DIR__"jiaowai7",
    	]));
    	setup();
    	replace_program(ROOM);
}
