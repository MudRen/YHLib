#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
�غ�����Ե������������ֹ��ӣ������۴��αȣ���������������
һƬ̫ƽ���־���������һ��԰�����˽���������ʮ�����֡�����
����ҽ�����࿪��ҩ�̡�
LONG);
        set("exits", ([
            "north" : __DIR__"road13",
            "south" : __DIR__"road15",
            "east"      : __DIR__"yaodian",
            "west"      : __DIR__"qingbomen",
        ]));
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}

