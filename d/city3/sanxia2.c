#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��Ͽ");
        set("long", @LONG
�����ǳ�����Ͽ�е���Ͽ��Ҳ�����������һ��Ͽ�ȣ���
Ů��߸ߵ������ڽ��ߣ�ԶԶ��ȥ������һΪͤͤ��������Ů��
�����羰����ʤ�ա�
LONG);
        set("exits", ([
                "east" :  __DIR__"sanxia1",
                "west" : __DIR__"sanxia3",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}

