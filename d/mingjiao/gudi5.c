#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", HIW "�����ɾ�" NOR);
        set("long", @LONG
�������˶���ֻ࣬���ͱ�����һ�����ٲ�������£�������
ѩ�ڶ��ɣ���������������һ��������������׳�����ٲ�й��һ��
�峺���̵���̶(tan) ֮�У�̶ˮȴҲ����������������йˮ��ȥ
·��
LONG);
        set("outdoors", "mingjiao");
        set("resource/water", 1);
        set("exits", ([
                "east" : __DIR__"gudi3",
        ]));
        set("item_desc", ([
                "tan" : HIC "\n�����ٲ��µ�һ���峺���̵�"
                        "��̶���㸽��̶�ߣ�������ȥ��ֻ��"
                        "\n���̵�ˮ��ʮ���������(fish)��"
                        "���ζ���\n" NOR,

               "fish" : HIW "\n��������̶�еİ��㣬ȫ���"
                        "�ۣ�����һ�߶೤��������̶������"
                        "\n��ȥ������˲�����ȥ׽(zhuo)һ"
                        "����\n" NOR,
        ]));
        setup();
}

void init()
{
        add_action("do_zhuo", "zhuo");
}

int do_zhuo(string arg)
{
        object me = this_player();
        object ob;

        if ((! arg) || ! ((arg == "fish") || (arg == "�����")))
                return notify_fail("��Ҫ��ʲô��\n");

        if (query("not_fish"))
        {
                message("vission", HIY "̶�еİ����Ѿ��ܾ���ȫ"
                                   "������̶�ף�û����׽�ˡ�\n"
                                   NOR, me);
                return 1;
        }

        message_vision(HIW "\n$N" HIW "�����ط��ڰ��ߣ���һ��"
                       "����������ǰ����Ȼһ�ƻ��䡣\n" NOR, me);
 
        if (me->query("combat_exp") < 100000)
        {
                message("vission", HIR "̶�еĴ�����ʱ����"
                                   "��æ����ȥץ����Ȼ��������"
                                   "��ȴһ�������ˡ�\n\n" NOR, me);
	        set("not_fish", 1);
                return 1;
        }

        ob = new(__DIR__"obj/fish");
        ob->move(me);
        message_vision(HIR "̶�еĴ�����ʱ����$N" HIR "��"
                       "æ����ץס��һ�Ѱ���߬�����ġ�\n\n" NOR, me);
        set("not_fish", 1);
        return 1;
}
