#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
����ɽ����ֻ���������£��Ǹ���Զ���Ŀ�����������
ȥ��ֻ�����޳�����һ��СС�ĺڵ㣬��Ŀ������ȴãã����
�������棬ֻ��һ������ʴ�һ�㣬�Ǿ��ǳ����ˡ�
LONG);
        set("exits", ([
                "eastdown" : __DIR__"qingshan2",
                "westdown" : __DIR__"qingshan1",
                "southdown" :__DIR__"chibi1"
        ]));
        set("objects", ([
                "/d/beijing/npc/youke" : 1,
        ]));
        set("no_clean_up", 0);
        set("outdoors", "jingzhou");
        setup();
        replace_program(ROOM);
}

