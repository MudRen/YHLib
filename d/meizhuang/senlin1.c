// senlin1.c

inherit ROOM;

#include <ansi.h>

void create()
{
        set("short", "��ľ԰");
        set("long", @LONG
������÷ׯ�İ�ľ԰����һ�ߵ���������ߵ���һ�������޾�
��Сɭ��һ��������������������������������кܶ�в�������
�ֵ�������ľ��
LONG
        );
        set("exits", ([
            "south" : __DIR__"keting",
            "north" : __DIR__"neiyuan",
            "east" : __DIR__"senlin2",
            "west" : __DIR__"neitang",
        ]));

        set("outdoors", "meizhuang");
        setup();
	replace_program(ROOM);
}

