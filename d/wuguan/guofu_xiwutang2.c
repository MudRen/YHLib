#include <room.h>

inherit ROOM;

void create()
{
        set("short", "ϰ����");
        set("long", @LONG
�����ǹ�����ϰ���ã�����һ����ͷ�ڽ����书��������
���������ͷѧϰ�����������Ϸ����Ÿ��ң�����д�ųԵ�
���п࣬��Ϊ�����ˡ�
LONG);
        set("no_fight", 1);
        set("exits", ([
                "north" : __DIR__"guofu_shilu-2",
        ]));
        setup();
        replace_program(ROOM);
}
