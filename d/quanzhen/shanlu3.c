inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
ǰ�������һ����ɽ�ȣ��ߵ������ľ����Щ��ȫ����
������������һ��������ɽ·��������ɽ�䣬Ҫ��ҹ�ﻹ�濴
��������
LONG);
        set("outdoors", "quanzhen");
        set("exits", ([
                "southwest" : __DIR__"shanlu2",
                "northup" : __DIR__"cuipinggu",
        ]));
        setup();
        replace_program(ROOM);
}
