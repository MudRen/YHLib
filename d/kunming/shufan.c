#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",  "�鷿" );
        set("long", @LONG
����һ�������������鷿���ıڶ�����ܣ���������˸�
���鼮���м�һ�����ӣ����ű�īֽӡ��
LONG);
        set("exits", ([
                "east"   :__DIR__"xizoulang1"
                
        ]));
        set("objects",([
                __DIR__"npc/wusangui" : 1,
                __DIR__"obj/pingfeng" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
