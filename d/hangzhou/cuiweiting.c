#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��΢ͤ");
        set("long", @LONG
��΢ͤ���ڷ�����İ�ɽ���䣬��������������Ϊ�������ɶ���
�ġ������С����곾�������£�����Ѱ���ϴ�΢����ʫ�䣬�ʴ�ͤ��
Ϊ����΢������������ɽ��·��
LONG);
        set("exits", ([
                "west"  : __DIR__"qinglindong",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
