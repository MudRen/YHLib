#include <room.h>

inherit ROOM;

void create()
{
        set("short", "����ׯ");
        set("long", @LONG
��������վ�ڷ�����������Ӻ��ϵĺ���ׯ���ˮƾ��������
���̵ĺ��棬���Ƕ����ˡ�
LONG);
        set("exits", ([
            "west" : __DIR__"road9",
        ]) );
        set("objects", ([
                "/adm/npc/hongniang" : 1,
        ]));

        set("no_fight",1);
        setup();
        replace_program(ROOM);
}

