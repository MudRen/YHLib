#include <room.h>
inherit ROOM;

void create()
{
        set("short", "ѧ��");
        set("long", @LONG
����������ڵ�һ��Сѧ�ã������������ʶ�������һ��
��������������Ľ��ţ�������������Ӻ����ӣ��������Ǳ�
ǽ��д�˼���������׳��Ŭ�����ϴ�ͽ�˱���
LONG);
        set("no_fight", 1);
        set("exits", ([
                "south" : __DIR__"guofu_shilu-1",
        ]));
        set("objects", ([
                __DIR__"npc/zhuziliu" : 1,
        ]) );
        setup();
        replace_program(ROOM);
}
