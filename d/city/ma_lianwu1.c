#include <room.h>
inherit ROOM;

void create()
{
        set("short", "���䳡");
        set("long", @LONG
�����ĳ�����������ϸϸ�Ļ����������ʺ����䡣������
����ؤ��ĵ����������䡣���䳡���������ż���ľ׮��ľ׮
��Χ���������ɸ���ɳ�ӡ������Ǳ����⡣���ұ���һ��С�š�
LONG);
        set("outdoors", "city");
        set("exits", ([
                "west"  : __DIR__"ma_bingqi",
                "east"  : __DIR__"ma_xiaojing",
                "south" : __DIR__"ma_zoulang2",
        ]));
        set("objects", ([
                "/d/gaibang/npc/1dai" : 1 + random(2),
                "/d/gaibang/npc/2dai" : 1,
                "/d/gaibang/npc/6dai" : 1,
                "/d/gaibang/npc/7dai" : 1,
        ]));
        create_door("east", "ľ��", "west", DOOR_CLOSED);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
