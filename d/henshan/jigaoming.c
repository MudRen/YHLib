#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������̨");
        set("long", 
"�����Ǹ�������ߴ����������������顸" HIW "������" NOR "��"
"������\n���ڴˣ��⼴���༫��(���޼�����)����⼫��(������"
"����)\n�������������ϵģ���Ի������̨��\n"
);
        set("exits", ([ 
               "northdown"  : __DIR__"sansheng",
        ]));

        set("objects", ([
                __DIR__"npc/youke" : 4,
        ]));    

        set("outdoors", "henshan");

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

