#include <ansi.h> 

inherit ROOM;

void create()
{
        set("short", "�ؽ�¥����");
        set("long", @LONG
�����Ǻ컨��������޳������ľ���֮�����޳������ų�
׷�����������˽��˵���Ϊ���ؽ�¥����¥�����㣬����¥
�ϸ���һЩ������е�ǽ��(wall)�ϻ���һЩС�ˣ��ƺ���
��������
LONG);
        set("no_clean_up", 0);
        set("item_desc", ([
                "wall" : WHT "\nǽ���ϻ���һЩ����������С�ˣ�����"
                         "�뽣���йء�\n" NOR,
        ]) );
        set("exits", ([
  		"down" : __DIR__"hh_jianlou2",
	]));
        setup();
}

void init()
{
        add_action("do_think", "think");
}

int do_think(string arg)
{
        object me;
        object weapon;
        me = this_player();

        if ( ! living(me)) return 0;

        if ( ! living(this_player()) || arg != "wall" )
                return notify_fail("��Ҫ����ʲô��\n");

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if ((int)me->query_skill("sword", 1) < 150)
                return notify_fail("�㷢��ǽ�������صĽ������ڸ����"
                                   "���޷���ᵽ�κζ�����\n");

        if ((int)me->query_skill("sword", 1) > 160)
                return notify_fail("�㷢��ǽ�������صĽ������ڷ�ǳ����"
                                   "���޷���ᵽ�κζ�����\n");

        if ((int)me->query("jing") < 100)
                return notify_fail("�����ھ��񲻼ã�����ƣ�룬������Ϣ"
                                   "һ��ɡ�\n");

        me->receive_damage("jing", 80);

        if (me->can_improve_skill("sword"))
                me->improve_skill("sword", me->query("int"));

        me->start_busy(random(2));
        message_vision(HIY "\n$N" HIY "�۾�����Ĳ���ǽ�������صĽ�����"
                       "��������\n" NOR, me);
        write(HIC "��ԡ����������������µ�����\n" NOR);
        return 1;
}
