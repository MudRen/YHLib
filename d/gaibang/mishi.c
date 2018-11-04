inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ��������������ң��ӵ��Ϻ��Ļҳ����ó�����
��������˳��룬�����ߵĵ��Ϸ���һ�����ͣ�����һ������
����ǽ�ϣ���֪����������ʲ���ˣ������ǽ(wall)���ú�ɼ
ľ���ģ�����������Ļ���ǽ�������Ե���Щ��Ѱ����
LONG);
        set("exits", ([
                "east" : __DIR__"undertre",
        ]));
        set("item_desc", ([
                "wall" : WHT "����һ�°߰������ǽ��ǽ"
                         "����������д����С�֣��ƺ���"
                         "���ȷ��йء�\n" NOR,
        ]));
        setup();
}

void init()
{
        add_action("do_think", "think");
}

int do_think(string arg)
{
        object me = this_player();

        if (! living(me))
                return 0;

        if (! living(this_player()) || arg != "wall")
                return notify_fail("��Ҫ����ʲô��\n");

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if ((int)me->query_skill("staff", 1) < 80)
                return notify_fail("�㷢��ǽ�������ص��ȷ����ڸ����"
                                   "���޷���ᵽ�κζ�����\n");

        if ((int)me->query_skill("staff", 1) > 180)
                return notify_fail("�㷢��ǽ�������ص��ȷ����ڷ�ǳ����"
                                   "���޷���ᵽ�κζ�����\n");

        if ((int)me->query("jing") < 120)
                return notify_fail("�����ھ��񲻼ã�����ƣ�룬��������"
                                   "Ϣһ��ɡ�\n");

        me->receive_damage("jing", 50 + random(60));

        if (me->can_improve_skill("staff"))
                me->improve_skill("staff", me->query("int"));

        me->start_busy(random(2));
        message_vision(HIY "\n$N" HIY "�۾�����Ĳ���ǽ�������ص��ȷ���"
                       "��������\n" NOR, me);
        write(HIC "��ԡ������ȷ��������µ�����\n" NOR);
        return 1;
}
