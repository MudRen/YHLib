#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
�����ڶ�����ϣ����ż�ʵ����ʯ����档����һ����
ֱ�Ĵ�������߿���ͨ�������ţ����ϱ�ͨ���ϴ�֣����Ϸ�
��������������¥�����߲�Զ����һ�����õķ��ݣ���������
������ (liang)�Ѿ����������ŷ��˸���ʵ��
LONG );

        set("outdoors", "chengdu");
        set("exits", ([
            	"southeast"  : __DIR__"wangjianglou",
            	"southwest"  : __DIR__"southroad1",
            	"north"      : __DIR__"eastroad2",
        ]));

        set("item_desc", ([
            	"liang" : "���ӵ��������������ŷ��˸���ʵ��\n"
        ]) );

        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_break", "break");
}

int do_break(string arg)
{
        int n;
        object weapon, me = this_player();

        if (arg != "liang")
        	return 0;

        if (query("break"))
                return notify_fail("�����Ѿ�����ɣ��ò����ٷ����ˡ�\n");

        message_vision(HIY "$N" HIY "�ߵ���ǰ������˫�ƣ��͵ػ�"
                       "������ķ�����\n" NOR, me);

        if (me->query("max_neili") < 1000)
        {
               message_vision(HIR "���ֻ��һ���ƺߣ�$N" HIR "��"
                              "�����ã�������������ǰ��ʱһ�ڡ�"
                              "��\n" NOR, me);
               me->set("neili", 0);
               me->unconcious();
               return 1;
        }

        message_vision(HIY "ֻ��һ�����죬������ʱ��$N" HIY "��"
                       "�÷���¶���˴��ţ�\n" NOR, me);

        set("exits/enter", __DIR__"minju");
        me->set("neili", 0);
        set("break", 1);
        return 1;
}
