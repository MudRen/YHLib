#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", WHT "�ڶ�ָ��" NOR );
        set("long", @LONG
�����ѵ�����ָ��İ�ɽ���ˣ���������ɽ���е�����ָһ����ÿ��ɽ
�����ٷ�Ϊ���أ�������ָ��ָ��һ�㣬�������������λ�ڵڶ�ָ�ڵ�λ
�á�������嶥�ѽ���͸���������������ѿ��Կ���ɽ·�ľ�ͷ�ˡ���ǰ
����ʮ���ɴ��������������һ����Ѩ(dong)������������ʯ���޽��ü���
������
LONG    );
        set("exits", ([
                "south" : __DIR__"sslin-5",
                "northup" : __DIR__"shanlu-8",
                "enter" : __DIR__"dong-1",
]));
        set("objects", ([
                __DIR__"npc/mayi" : 2,
]));

        set("item_desc", ([ 
                "dong" : WHT "һ���������ɽ�����ڰ���ż���м����׹�������\n" NOR,
]));
        set("no_clean_up", 0);
        set("outdoors", "tiezhang");
        setup();
}

int valid_leave(object me, string dir)
{        
        if (dir == "enter" && objectp(present("mayi zhanglao", environment(me))))
           return notify_fail(CYN "���³��Ϻȵ����������ư���أ��κ��˲������ڣ���������������\n" NOR);
                
        return ::valid_leave(me, dir);
}
