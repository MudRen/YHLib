#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������¥����");
        set("long", @LONG
������������¥�Ĵ������൱�Ŀ���һ��������Ů�������ã���Ů
ǰ����һ��޴�ĺ�ľ�������ܣ�����վ�����ױ����ų��������ɡ�
LONG );
        set("exits", ([ 
                "down" : __DIR__"was_lou3",
        ]));
        set("objects", ([
                "/d/tulong/yitian/npc/ada" : 1,
                "/d/tulong/yitian/npc/aer" : 1,
                "/d/tulong/yitian/npc/asan" : 1,
                "/d/tulong/yitian/npc/he" : 1,
                "/d/tulong/yitian/npc/zhao" : 1,
                "/d/tulong/yitian/obj/shelf" : 1,
        ]) );

        setup();
}
