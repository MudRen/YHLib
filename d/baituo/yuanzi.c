#include <room.h>
inherit ROOM;

void create()
{
        set("short", "Ժ��");
        set("long", @LONG
����һ����Ժ�ӣ���ɨ��һ����Ⱦ������װ���ż�������
���񣬴������¡������������⡣������һ�䴢���ң����Ź�
���š������ǰ���ɽׯ�Ĵ������ϱ߾��Ǵ����ˡ�
LONG);
        set("exits", ([
                "northup" : __DIR__"dating",
                "west"    : __DIR__"wuqiku",
                "east"    : __DIR__"storeroom",
                "south"   : __DIR__"damen",
        ]));
        create_door("east", "ľ��", "west", DOOR_CLOSED);
        setup();
        replace_program(ROOM);
}
