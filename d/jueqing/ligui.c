#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
�˴��Ǿ���ȶ��������壬���������ഫ������������
���磬����˭Ҳ����������һ������������������˲���ë
���Ȼ������һ��������
LONG);
        set("outdoors", "jueqing");
        set("exits", ([
               "southwest" : __DIR__"shanlu6",
        ]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
