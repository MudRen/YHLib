#include <room.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
���Ƕ�¥�������ϣ�����˷����Ǵ������䵱������ȥ
�Ҵң�����æ�Ų�����
LONG);
        set("exits", ([
                "south" : __DIR__"caolian1",
                "north" : __DIR__"caolian2",
                "west" : __DIR__"caolian3",
                "eastdown"  : __DIR__"xilang"
        ]));
        set("objects", ([
                CLASS_D("wudang") + "/yin" : 1
        ]));
        setup();
        replace_program(ROOM);
}
