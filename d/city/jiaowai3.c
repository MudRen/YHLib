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
        	"north" : __DIR__"jiaowai2",
        	"south" : __DIR__"jiaowai4",
    	]));
    	set("objects", ([
        	__DIR__"obj/shitou": 2,
    	]));
    	setup();
    	replace_program(ROOM);
}

