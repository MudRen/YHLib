#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���������");
        set("long", @LONG
����վ�ھ��ݱ�������ſڣ����Կ������������Ʒ��Ĺ�
�����ڴ˵�Ѳ�ߣ���ʱ�ش����ź������ϰ����ǲ������ڴ˹�
���ģ�����øϿ��߿���
LONG);
        set("exits", ([
                "east" : __DIR__"nandajie2",
        ]));
        set("objects", ([
                "/d/city/npc/bing" : 2,
        ]));

        setup();
        replace_program(ROOM);
}
