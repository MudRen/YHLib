#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��Ժ���");
        set("long", @LONG
���С���ţ�ӭ����һͤԺ���Ա�����ʯ�������⡰��Ժ��ɡ���
�����ǻ��յ̡�
LONG);
        set("exits", ([
            "west"     : __DIR__"suti2",
            "enter"    : __DIR__"quyuanfenghe",
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
