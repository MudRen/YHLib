#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ʯС��");
        set("long", @LONG
������һ����ʯС���������ɵ�����������µڶ����ð�
���õĴ��ţ����ﲻʱ�а׻��õĵ����߶���
LONG);
        set("outdoors", "heimuya");
        set("exits", ([
                "west" : __DIR__"baigate",
                "south" : __DIR__"baigate2",
        ]));
        setup();
        replace_program(ROOM);
}
