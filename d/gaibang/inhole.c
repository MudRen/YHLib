#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�����ڲ�");
	set("long", @LONG
�������ݳ�����㳡���������ڲ���Ҳ��ؤ�����ܵĵ���
ͨ�����ܽ��㴦�������ﶪ���˸���������������һ�ɳ����
��ζ�����������϶���һ��ǳ���Ŀ��ľ�ơ�
LONG);
	set("exits", ([
		"out"  : "/d/city/guangchang",
		"down" : __DIR__"undertre",
	]));
	set("objects", ([
                "/d/gaibang/npc/2dai" : 1 + random(2),
                "/d/gaibang/npc/1dai" : 1 + random(2),
		CLASS_D("gaibang") + "/li" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
        object guard;

        if (dir != "down"
           || ! objectp(guard = present("li sheng", this_object())))
                return ::valid_leave(me, dir);

        return guard->permit_pass(me, dir);
}
