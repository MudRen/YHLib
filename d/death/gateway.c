#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR "��ۺ�����š�" NOR);
       set("long", HIR @LONG

                    ۺ     ��     ��     ��

    ����������һ����ɫ�ĳ�¥֮ǰ����¥�ϵ������ۺ���ǡ�������
�֡����ϲ�Զ����һ��ʯ�ţ����Ϲ�Ӱ����������ȴ���������������
�����߽���¥ֻ��һƬ������ģ�ֻ��������ɫ�Ļ���������ֵ���
˸����


LONG NOR );
	set("exits", ([
		"north" : __DIR__"road1",
		"south" : __DIR__"gate",
	]));
	set("objects", ([
		__DIR__"npc/hei": 1,
	]) );

	set("no_fight", 1);
	set("no_sleep_room", 1);

	setup();
}

int valid_leave(object me, string dir)
{
	if( wizardp(me) || !userp(me) ) return 1;

	if (dir == "south") {
		return notify_fail(HIW "\nһ���ն�����������������𡭡�û�л�ͷ·�ˡ���\n" NOR);
	}
	else return 1;
}

