#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���������");
        set("long", @LONG
�����Ǵ���������㣬���������������������졣�����
����Ҳ������Ҳ��ȫ��ȫ������ǽ�ȥ�Ķ��ˡ�
LONG);
        set("exits", ([
                "westup" : __DIR__"cundaota4",
                "westdown" : __DIR__"cundaota2",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
