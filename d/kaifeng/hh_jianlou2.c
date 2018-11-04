#include <ansi.h> 

inherit ROOM;

void create()
{
        set("short", "�ؽ�¥����");
        set("long", @LONG
�����Ǻ컨��������޳������ľ���֮�����޳������ų�
׷�����������˽��˵���Ϊ���ؽ�¥����¥�����㣬���¥
�����κγ��衣�����ϻ���һ������ (bagua)���ƺ���Ϊ����
�������á�
LONG);
        set("no_clean_up", 0);
        set("item_desc", ([
                "bagua" : WHT "\n��������ƺ���Ϊ�����������ã���"
                          "�������Ű�����(zou)�߿���\n" NOR,
        ]) );
        set("exits", ([
  		"down" : __DIR__"hh_jianlou1",
  		"up" : __DIR__"hh_jianlou3",
	]));
        setup();
}

void init()
{
        add_action("do_zou", "zou");
}

int do_zou(string arg)
{
        object me;
        object weapon;
        me = this_player();

        if ( ! living(me)) return 0;

        if ( ! living(this_player()) || arg != "bagua" )
                return notify_fail("��Ҫ��ô�ߣ�\n");

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if ((int)me->query_skill("lianhuan-mizongtui", 1) < 10)
                return notify_fail("�����Ű���ͼ������Ȧ���������ƺ�û"
                                   "ʲôЧ����\n");

        if ((int)me->query_skill("lianhuan-mizongtui", 1) > 180)
                return notify_fail("�����Ű���ͼ������Ȧ�������Լ�����"
                                   "���������Ѿ�������ͨ���߰��������"
                                   "�ˡ�\n");

        if ((int)me->query_skill("unarmed", 1) < (int)me->query_skill("lianhuan-mizongtui", 1))
                return notify_fail("��Ļ���ȭ��ˮƽ���ޣ��޷�������"
                                   "������������ȡ�\n");

        if ((int)me->query("qi") < 30)
                return notify_fail("��������Ѫ���ڣ�����ƣ�룬������Ϣ"
                                   "һ��ɡ�\n");

        me->receive_damage("qi", 20);

        if (me->can_improve_skill("lianhuan-mizongtui"))
                me->improve_skill("lianhuan-mizongtui", me->query("dex") * 10);

        me->start_busy(random(2));
        message_vision(HIY "\n$N" HIY "������ˮ������Ű���ͼ��������һ"
                       "Ȧ��\n" NOR, me);
        write(HIC "��ԡ����������ȡ������µ���⡣\n" NOR);
        return 1;
}
