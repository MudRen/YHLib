#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short", "ĥ�뾮");
        set("long", @LONG
�ഫ���������ɽ�������վ�˼�飬ż��һ�ϸ���������
ĥ����ĥ��Ϊ�Σ�����ĥ�롣������������ĥ�룿���ƹ�����
Ȼ�ɡ������ɴ����������������ɡ�������ĥ�뾮������
Ϊ�����ǰ��������һ������������ĸͤ��ͤ�����о���
LONG);
        set("exits", ([
                "west" : __DIR__"shanlu1",
        ]));
        set("item_desc",([ 
                "jing" : HIC "\n���ع��ӣ�ˮɫ����������װƿ���á�\n\n" NOR,
        ]));
        set("resource/water", 1);
        set("outdoors", "wudang");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
