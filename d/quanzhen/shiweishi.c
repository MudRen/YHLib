#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��Ϊ��");
        set("long", @LONG
������ȫ������֮�����ڵľ��ҡ������С��ֻ�ڷ�һ��
����һ��������һ�����ӡ������Ϸ��ű����ӣ����ϱ����۵�
���������롣
LONG);
        set("exits", ([
                "south" : __DIR__"cetang",
        ]));

        set("objects", ([
                CLASS_D("quanzhen") + "/ma" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
