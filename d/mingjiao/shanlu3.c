#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����ɽ·���ͣ�����һ�˶��·�����ͱڸ��ʣ�·�ҽ�����
����Ԩ��ʵ����һ�򵱹ء����Ī������Ҫ֮�����������ʣ���Ҫ
���������������ˡ�����·�ң���Ȼ����һ���ʯ���߽����ɣ���
Ϊ������ʯ����������������Զ���ƺ���
LONG );
	set("exits", ([
		"southdown" : __DIR__"shanlu2",
		"northup"   : __DIR__"shanlu4",
		"up"        : __DIR__"xuantianshi",
	]));

	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	setup();
}

int valid_leave(object me, string dir)
{
    	if ((random((int)me->query_skill("dodge")) <= 30) && dir=="up")    
    	{
        	return notify_fail(HIR "��ʹ����һ�ģ���ʯ����������Զ"
                                   "�͵���������ˤ�ı������ס�\n" NOR);
    	}
    	if ((random((int)me->query_skill("dodge")) <= 50) && dir=="up")    
    	{
        	return notify_fail(HIY "�����һԾ��ȴ��ʯ������һ�ɶ�"
                                   "Զ�������ǰ׷�������\n" NOR);
    	}
    	if ((random((int)me->query_skill("dodge")) <= 80) && dir=="up")
    	{
        	return notify_fail(HIY "�����������ʯ��ֻ��һ�����"
                                   "���ټӰѾ���\n" NOR);
    	}
    	return ::valid_leave(me, dir);
}

