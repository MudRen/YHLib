#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�߲��Թ�");
        set("long", @LONG
������������ĳ�������ǰ����������������Թ�֮
�ڲ����㼣ָ�����㲻֪��Ҫ������·�ߡ�����ϸ����������
���׺�ǰ������·�϶��е������㼣�����ƺ���ʧ�˷�����
ûͷ��Ӭ�㵽���Ҵ���
LONG);
        set("exits", ([
                "east" : __DIR__"shulin" + (random(8) + 6),
                "west" : __DIR__"shulin" + (random(8) + 6),
                "south" : __DIR__"shulin" + (random(8) + 6),
                "north" : __DIR__"shulin" + (random(8) + 6),
        ]));

        set("outdoors", "gaochang");
        setup();
}

void init()
{
        object me = this_player();

        if (userp(me) && random(2) == 0)
	{
        	message_vision(HIR "\n$N" HIR "һ��С�Ĵ����˻��أ���ʱֻ����ͷ"
                               "��һ����죬һ���ʯ��ͷ���¡�\n$N" HIR "һ����"
                               "�У�ʹ�ü���ʧȥ��֪������\n" NOR, me);
        	if ((int)me->query("eff_qi") < 80)
		{
                        me->set_temp("die_reason", "����ʯ������");
			me->die();
		} else
		{
	                me->receive_wound("qi", 80);
			me->unconcious();
		}
	}
        return 0;
}

