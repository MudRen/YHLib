#include <login.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "���ҹ�������");
        set("long", @LONG
����һ������ྻ�ĵ����ң��ı��ù⻬�Ĵ���ʯ���Ͷ�
�ɣ�ʮ��֧�����յ�����ͨ��͸����
LONG );
        set("objects", ([
           	CLASS_D("wudang") +"/xiaosong": 1,
        ]));

        set("exits", ([
                "up"     : __DIR__"nanyangong",
                "east"   : __DIR__"nanyan1",
                "west"   : __DIR__"nanyan2",
                "south"  : __DIR__"nanyan3",
                "north"  : __DIR__"nanyan4",
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
    	if (dir == "up")
    	{
       		if (me->query_skill("taiji-shengong", 1) < 80)
              		return notify_fail(HIY "�����������ƶ��ϵ�ש�ǣ���"
                                           "�ֱ�������˿������\n" NOR);

          	message_sort(HIY "\n$N" HIY "ȫ������̫���񹦣���������ٵ�"
                             "һ��������˫�������ͻ���ֻ��һ�ɰ�����$N" HIY
                             "���Ķ�����Ѹ���ޱȵػ��ж��ϵ�ש�ǡ�������һ"
                             "�����죬ש�Ǳ��������С��Ƭ��ɢƮ�ɡ�¶��һ"
                             "�����ϵĶ�������\n\n" NOR, me );
     	}
     	return ::valid_leave(me, dir);
}
