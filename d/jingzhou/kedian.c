#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "�͵�");
	set("long", @LONG
����һ�Ҽ�Ǯ�����Ŀ�ջ����������嵭������ο�ż��
ѡ��������ţ���������ס��ҪС�ģ���˵�����кڵꡣ
LONG);
	set("no_fight", 1);
	set("valid_startroom", 1);
        set("no_sleep_room",1);
	set("item_desc", ([
		"paizi" : "¥���ŷ���ÿҹ��ʮ��������\n",
	]));
	set("objects", ([
		"/d/city/npc/xiaoer2" : 1,
	]));
	set("exits", ([
                "east" : __DIR__"majiu",
		"west" : __DIR__"beidajie1",
		"up" : __DIR__"kedian2",
	]));
	setup();
}

int valid_leave(object me, string dir)
{

	if (! me->query_temp("rent_paid") && dir == "up" )
        	return notify_fail(CYN "��С��һ�µ���¥��ǰ������һ"
                                   "���������ţ����ס����\n" NOR);

	return ::valid_leave(me, dir);
}
