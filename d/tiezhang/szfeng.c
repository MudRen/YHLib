#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR "ʳָ��" NOR);
        set("long", @LONG
�����������˷嶥���Ѿ��۵����������ˡ�����ֻ������Բ��һС��
�ط�����ݲ������������ǹ�ͺͺ����ʯ��һ�����Х������������һ��
���򣬲��ˤ�����������ǸϿ��뿪����ĺá�
LONG );

        set("exits", ([
                "southdown" : __DIR__"juebi-1",
        ]));

        set("no_clean_up", 0);
        set("outdoors", "tiezhang");
        setup();
}