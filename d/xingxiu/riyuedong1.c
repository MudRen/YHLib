#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���²ප");
        set("long", @LONG
�������������ܶ����ڵ����¶��ප��ֻ�����һƬ��Ψ
��ǰ����Ա����Щ����ߣ��������Դ����ȥ��
LONG);
        set("exits", ([
             "out" : __DIR__"xxh1",
        ]));

        setup();
        replace_program(ROOM);

}

