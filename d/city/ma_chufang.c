#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��");
        set("long", @LONG
����һ�䰫С���߷���ƽʱ��Ϊ�ѷ��������á������ﲼ
�����������������ǻҳ����������Ѿ��ܾ�û���˴�ɨ�ˡ���
����һ��б���ż����ɲ�
LONG);
        set("exits", ([
                "west" : __DIR__"ma_dayuan",
        ]));
        set("no_clean_up", 0);
        set("objects", ([
                "/d/wudu/obj/ganchai" : 2,
        ]));
	setup();
}

void init()
{
        object me = this_player();

        if (me->query("family/family_name") == "�嶾��")
        {
                tell_object(me, HIR "\n��ͻȻ����һֻɫ�ʰ�쵵�֩�룬��"
                                "���嶾�̵Ķ������š�\n" NOR);
                me->set_temp("want_back_wudu", 1);

                remove_call_out("letter");
                call_out("letter", 3, me);
        }
        add_action("do_back", "back");
}

void letter(object me)
{
        if (environment(me) != this_object())
                return;

        if (! me->query_temp("want_back_wudu")) 
                return;

        tell_object(me, WHT "  ����������������\n"
                            "  ����ˮ�����Щ�\n"
                            "  �������ܵ��ܹ���\n"
                            "  ��ֱͨ(" HIY "back" NOR + WHT ")�婧\n"
                            "  ������  ���ư���\n"
                            "  ����������������\n" NOR);
}

int do_back()
{
        object me = this_player();

        if (me->query_temp("want_back_wudu")) 
        {
                message("vision", HIC "��Ȼ��ֻ��" + me->name() +
                                  HIC "����һ�Σ���û����Ӱ��\n" NOR,
                                  environment(me), ({me}));
                me->move("/d/wudu/midao5");
                tell_object(me, HIC "\n������˲�ˮ���µ��ܵ���\n\n" NOR);
        }
        return 1;
}
