#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","С·");
        set("long", @LONG
һ����᫵Ļ���С·��·���Ӳݴ��������߿��Կ�������
�Ĺٵ�����ȥ���һ�������ݡ�
LONG);
        set("exits", ([
  		"east" : __DIR__"road6",
  		"west" : __DIR__"guandao1",
  	]));
        set("no_clean_up", 0);
        set("outdoors", "jingzhou");

        setup();
        replace_program(ROOM);
}

