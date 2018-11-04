inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
�˴����Ƹ��ʣ����Ǻ�ľ���ϣ�����վ����������̵ĵ�
�ӡ����ԵĿ������д��֣������ǡ��ĳ���¡��������ǡ���
��Ӣ����������Ͽ��š����¹������ĸ�����֡��±߾��ż�
����ڴֵ�������������һ��ϵ��һ������(basket)��
LONG);
        set("outdoors", "heimuya");
        set("exits", ([
            "north" : __DIR__"shanya2",
        ]));
        set("objects", ([
                __DIR__"npc/dizi2" : 4,
        ]));
        set("item_desc", ([
                "basket" : "һ�����޴�ĵ������ǹ����������������ɽ֮�á�\n"
        ]) );
        setup();
}
  
void init()
{
        add_action("do_enter", "enter");
        add_action("do_float", "float");
        add_action("do_float", "piao");
}

int do_enter(string arg)
{
        object me, myenv;
        me = this_player();

        if (! arg || arg != "basket" )
                return notify_fail("ʲô��\n");

        if (me->query("family/family_name") != "�������")
                return notify_fail(CYN "���µ��ӵ������һ�ۣ���Цһ����ת��ͷ"
                                   "ȥ��������Ҳ����\n" NOR);

        message_vision(HIY "\n$N" HIY "���ȵ�����������������µ��Ӵ�����ơ���"
                       "���ӵ��˵�ͷ����\n����һ�⣬�ſ�������������ʱ�������»�"
                       "ȥ��\n\n", me);
        myenv = environment(me);
        me->move ("/d/heimuya/basket");
        me->start_call_out((: call_other, __FILE__, "down1", me :), 3);
        return 1;
}

void down1(object me)
{
        tell_object(me, HIW "\n������ĵ��������½�������Ķ��������ϳ�ȥ��\n\n" NOR);
        me->start_call_out((: call_other, __FILE__, "down2", me :), 3);
}

void down2(object me)
{
        tell_object(me, HIG "\n��ʱ�䣬һƬ�����Ĳ�ƺ����������ǰ��\n\n" NOR);
        me->move("/d/heimuya/up1");
        message_vision(HIC "\n$N" HIC "���������Ӻ�ľ���ϻ���������\n\n" NOR, me);
}

int do_float()
{
        object me;

        me = this_player();

        if (me->query_skill("juechen-shenfa", 1) < 180)
        {
                message_vision("$N��ɽ������ȥ����˼���ã�̾�˿�����\n", me);
                return 1;
        }

        if (me->query("neili") < 100)
        {
                tell_object(me, "�������������������Ϣһ����˵�ɡ�\n");
                return 1;
        }

        me->add("neili", -80);

        message_sort(HIC "\n$N" HIC "��������һ����������ƮȻ���𣬳�ɽ"
                     "������ȥ��\n\n" NOR, me);
        me->move("/d/heimuya/up1");
        tell_object(me, "��ƮȻ������ľ��ɽ��֮�¡�\n");
        message("vision", HIC "\n����һ����Х��Զ������" + me->name() +
                          HIC "�������ɽ��ƮȻ���¡�\n" NOR,
                          environment(me), ({ me }));
        return 1;
}

