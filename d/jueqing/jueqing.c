#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
������Ǿ���Ⱦ���֮������壬�����˴����Ⱥ�壬��
��Ⱥ����������ƣ��������ơ�����ǧ�����֣���ľ��������
�ǵ�ɽ�紵�������˸е������⡣
LONG);
        set("outdoors", "jueqing");
        set("exits", ([
               "southdown" : __DIR__"shanlu8",
        ]));

        set("no_clean_up", 0);
        
        setup();
        replace_program(ROOM);
}

