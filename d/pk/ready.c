#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "���˳���Ϣ��");
	set("long", @LONG
����ں����ģ����ϻ���һЩճ����Ѫ���Ĳ�����żȻ
Ҳ���õ����˵ĳ������ֵ�ʲô�ġ�������Ž������ţ���
��ɢ����һ����Ѫ�ȵ���ζ��
LONG);
	set("exits", ([
		"south" : __DIR__"entry",
	]));

        set("no_fight", 1);
	setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "south")
                message_vision("$N�Ĵ�������һ�£��������Ϣ�ҡ�\n", me);
        return 1;
}
