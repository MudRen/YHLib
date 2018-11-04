#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǹ�Ĺ�е����ң������ܲ�͸�磬��ֻ�ܽ���ǽ�ϻ�
���ĵƹ�����ǿ�ֱ淽��ǽ�����������ʯ���������ģ���
�ϵ����������������Դ����ҳ�һ˿��϶��ǽ��(wall)�����
��һЩ���֡�
LONG );

        set("item_desc", ([
                "wall": NOR + WHT "һ����������ʯ���϶��ɵ�ǽ���������źܶ����֣���"
                        "����\n����һЩ�ķ����Ͼ����ڡ�\n" NOR,
        ]) );

        set("exits", ([
                "east" : __DIR__"mishi3",
                "north" : __FILE__,
                "south" : __FILE__,
                "up" : __DIR__"houting",
        ]));

        setup();
}


void init()
{       
        add_action("do_think", "think");
}

int do_think(string arg)
{
        object here, me = this_player();
        int add;

        if (! here = find_object(__DIR__"mishi2"))
                here = load_object(__DIR__"mishi2");

        if (me->query("special_skill/clever"))
		add = me->query_int() * 4;
        else
		add = me->query_int() * 3;

        if (! living(me) || arg != "wall")
                return notify_fail("��Ҫ����ʲô��\n");

        if (me->is_busy() || me->is_fighting())
                return notify_fail("��������æ���ء�\n");

        if ((int)me->query_skill("sword", 1) < 30)
                return notify_fail("����ڹ���Ϊ�������޷�����ǽ"
                                   "�ϵ��ķ���\n");
     
        if (! me->query("can_learn/yunv-xinjing/wall"))
                return notify_fail("���о��˰��죬ȴ����ǽ���ϵ��ķ�"
                                   "��������\n");
            
        if ((int)me->query_skill("yunv-xinjing", 1) < 180)
                return notify_fail("�㷢��ǽ�������ص��ķ�������£���"
                                   "��һʱ��������\n");             

        if ((int)me->query_skill("yunv-xinjing", 1) > 240)
                return notify_fail("�㷢��ǽ�������ص��ķ����ڷ�ǳ����"
                                   "���޷���ᵽ�κζ�����\n");

        if ((int)me->query("jing") < 35)
                return notify_fail("�����ھ��񲻼ã�����ƣ�룬������Ϣ"
                                   "һ��ɡ�\n");

        me->receive_damage("jing", 30);

        if (me->can_improve_skill("yunv-xinjing"))
                me->improve_skill("yunv-xinjing", add);

        me->start_busy(random(2));
        message_vision(HIY "\n$N" HIY "�۾�����Ĳ���ǽ�������ص��ķ���"
                       "��������\n" NOR, me);
        write(HIC "��ԡ���Ů�ľ��������µ�����\n" NOR);
        return 1;
}


