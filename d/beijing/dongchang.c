inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "����");
        set("long", @LONG
������Ǿ��ǵ�����������������������ں��ǿ��������ﾯ�����ϣ���
���Ʒ��Ķ����ٱ���̫�������������߶�������������һλ���ϵ�̫�࣬����
��������ܹ��ˡ�
LONG NOR);

        set("exits", ([
                "north" : __DIR__"dongchang_men",
        ]));
        set("objects", ([
                __DIR__"npc/haigonggong" : 1,
                __DIR__"npc/taijian" : 4,
                __DIR__"npc/xiaoguizi" : 1,
        ]));
        set("no_fight", 1);
        setup();
        replace_program(ROOM);
}

