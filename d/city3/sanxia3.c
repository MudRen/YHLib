#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����Ͽ");
        set("long", @LONG
�����ǳ�����Ͽ�е�����Ͽ����ˮ�ɶ������������Ͽ�ȣ�
�ӵ���խ��ˮ���伱�������ĸ�ɽ�м����һ���������ͺ���
һ��˿��һ�㣬���Ѷ��С�
LONG);
        set("exits", ([
                "east" :  __DIR__"sanxia2",
                "west" : __DIR__"shudao11",
        ]));
        set("objects", ([
                "/d/beijing/npc/youke" : 1,
        ]));
        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
        replace_program(ROOM);
}

