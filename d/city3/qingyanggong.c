#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������µ�һ����ۡ�������ľ��涣��ڸ�ͤͤ����
��ʿ�Ҵ���ȥ��û�˵ÿ����㣬��û�˽Ӵ��㡣����õ�һ��
���ɵ�ʧ�䡣
LONG);
	set("exits", ([
		"northeast" : __DIR__"westroad1",
	]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
        object me = this_player();

        if (me->query("family/family_name") == "������")
        {
                tell_object(me, HIG "\n��ͻȻ���ֶ����ɵ������ڴ˴���"
                                "���š�\n" NOR);
                me->set_temp("want_leave", 1);

                remove_call_out("letter");
                call_out("letter", 3, me);
        }
        add_action("do_back", "back");
}

void letter(object me)
{
        if (environment(me) != this_object())
                return;

        if (! me->query_temp("want_leave")) 
                return;

        tell_object(me, WHT "  ����������������\n"
                            "  �������������Щ�\n"
                            "  �������ܵ��ܹ���\n"
                            "  ��ֱͨ(" HIY "back" NOR + WHT ")�멧\n"
                            "  ���һ����ִ�\n"
                            "  ����������������\n" NOR);
}

int do_back()
{
        object me = this_player();

        if (me->query_temp("want_leave")) 
        {
                message("vision", HIC "��Ȼ��ֻ��" + me->name() + HIC
                                  "����һ�Σ���û����Ӱ��\n" NOR,
                                  environment(me), ({me}));
                me->move("/d/emei/midao5");
                tell_object(me, HIC "\n�����������������ڵ��ܵ���\n\n" NOR);
        }
        return 1;
}
