#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����С·");
        set("long", @LONG
�����ڳ������ϵ�һ��С·�ϣ������Ž�ˮ������������
��Ҳ���ú�Щ������������ȥ��ֻ��Ⱥɽ���࣬Ҳ��֪���δ�
���ǹ�;��
LONG);
        set("exits", ([
  		"northeast" :  __DIR__"shudao2",
  		"west" : __DIR__"shudao4",
   	]));
        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        set("objects", ([
                "/d/beijing/npc/boy2" : 1,
                "/d/beijing/npc/girl4" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
