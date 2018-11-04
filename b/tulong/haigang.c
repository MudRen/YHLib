#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����֮��");
        set("long", @LONG
������Ǵ�֮�����˻��Ĵ��Ž�ʯ������������������
����һȺȺ��Ÿŷŷ�ؽ��ţ���ʱ�����Ծ�����棬������
�˻����������Ҵ�(boat)���������ż����������ˣ���
���ɶɹ��󺣵��ﺣ����һ�ˡ�����һֱ�߾����ྩ�ˣ�����
��һ���޼ʵĴ󺣡���Ŀ���������������ؿ��������⳩����
ȷ��һ���þӴ���
LONG);
        set("exits", ([
                "west"  : "/d/beijing/road10",
                "north" : __DIR__"haian",
        ]));

        set("item_desc", ([
                "boat" : "����һ�Ҵ󷫴�����úܽ�ʵ���������Գ�Զ���ġ�\n",
        ]));

        set("objects", ([
                "/d/shenlong/npc/chuanfu" :1,
        ]));

        set("outdoors", "beijing");
        setup();
}

void init()
{
        object me, dao, room, bai, ding;

        me = this_player();
        room = load_object("/b/tulong/huichang");
        ding = present("ding", room);

        if (objectp(ding)) 
        	dao = present("tulong dao", ding);

        if (objectp(dao))
        {
                room = load_object("/b/tulong/daobian");
                bai = present("bai guishou", room);

                tell_object(me, HIC "\nֻ�������ϲ����˺��������еĺ���ȫ���������"
                               "ӥ�̵ı�־��\n" NOR);

                if (objectp(bai)
                   && ! bai->query_temp("go")
                   && ! me->query_temp("to_wang")
                   && me->query("combat_exp") > 1000000
                   && me->query("weiwang") > 100000)
		{
              	        tell_object(me, CYN "\n�׹��ٶ���˵�����˴�����ӥ�̵õ�����"
                                        "����������λ����ͬ\n����Ը��μ��ﵶ������"
                                        "�ᣬѡ���˵���Ϊ�������У�\n" NOR);
                        tell_object(me, HIR "\n��Ը��μ�(" HIY "accept" HIR ")����"
                                        "ɽ���ﵶ���������\n" NOR);
                	me->set_temp("to_wang", 1);
                	add_action("do_accept", "accept");
		}
        }
}

int do_accept()
{
        object me, room, bai;

        me = this_player();
        room = load_object("/b/tulong/daobian");
        bai = present("bai guishou", room);

        if (! me->query_temp("to_wang"))
                return notify_fail("ʲô��\n");

        if (bai->query_temp("go"))
                return notify_fail("���ǿ�ϧ���Ѿ����˱�����һ���μ��ˡ�\n");

        tell_object(me, HIR "�����ȥ�μ��ﵶ������ᡣ\n\n" NOR);

       	bai->set_temp("go", 1);
        me->start_busy(15);

        remove_call_out("moveto");
        call_out("moveto", 10, me);
        return 1;
}

int moveto(object me)
{
        message_vision(HIC "\n$N" HIC "��������ӥ�̵Ĵ󴬣���������"
                       "�ֺ������������ˣ�����\n���������ʻ��"
                       "��\n\n" NOR, me);
        me->move("/b/tulong/boat");

        remove_call_out("arrive1");
        call_out("arrive1", 10, me);
        return 1;
}

int arrive1(object me)
{
        message_vision(HIB "\n��ӥ�̵Ĵ��ڴ���������Ư�š���$N"
                       HIB "�����е�˯�����ʡ�\n" NOR, me);

        remove_call_out("arrive2");
        call_out("arrive2", 10, me);
        return 1;
}

int arrive2(object me)
{
        message_vision(HIY "\n$N" HIY "ͻȻ����һ�����ȣ������ˣ���"
                       "���ɣ���$N" HIY "��ʱ�������\n����ӥ�̽�"
                       "�����˴���\n\n" NOR, me);
        me->move("/b/tulong/boat2");
        tell_object(me, HIC "\n�������ӥ�̵���������ɽ���ߡ�\n\n" NOR);
        return 1;
}
