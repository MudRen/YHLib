#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
�����������������µ�����ϣ���·ʮ����խ�����ﲻʱ
����ǿ����û���������˺��٣���Ŀ��ȥ����Բ��������û��
���̣��㻹�Ǽӿ첽���߰ɡ�
LONG);
        set("exits", ([
                "east" : __DIR__"shudao12",
  		"west" : __DIR__"shudao14",
        ]));
        set("objects", ([
                "/d/beijing/npc/haoke1" : 1,
        ]));
        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
        replace_program(ROOM);
}

