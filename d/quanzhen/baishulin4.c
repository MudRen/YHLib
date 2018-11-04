#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
���������ֵı�Ե���������Ķ��ˡ�����İ���Ҳϡ����
�ܶࡣ�Ա���һ�Թ�ľ(frutex)��������ľ����ǰ���������ˡ�
LONG);
        set("outdoors", "quanzhen");
        set("exits", ([
                "west" : __DIR__"baishulin3",
                "southdown" : __DIR__"baishulin2",
        ]));
        set("no_clean_up", 0);
        set("count",1);
        set("item_desc", ([
                "frutex": GRN "һ����в������ֵĹ�ľ�����м����źܶ�С�̡�\n" NOR,
        ]));

        setup();
}

void init()
{
        add_action("do_kan","kan");
}

int do_kan(string arg)
{
        object me = this_player();
        object weapon, ob;

        if (! arg || arg != "frutex" )
                return notify_fail("��Ҫ��ʲô��\n");

        if (! objectp(weapon = me->query_temp("weapon")))
                return notify_fail("���üһ���²��аɣ�\n");

        if (query("count") > 0)
        {
                message_sort(HIC "\n$N" HIC "�γ����У��ߵ���ľ�Ը�ǰһ����"
                             "��������ǰһЩ�����Ĺ�ľ�����Ժ�$N" HIC "��"
                             "������������һ��ʲôС�ݣ�����˳�ְ���������û"
                             "�뵽�������źô�һ���������Ȼ��һ����͵�����"
                             "��\n" NOR, me);
                add("count", -1);
                ob = new(__DIR__"obj/fuling");
                ob->move(me, 1);
        } else
        {
                message_sort(HIC "\n$N" HIC "�γ����У��ߵ���ľ�Ը�ǰһ����"
                             "��������ǰһЩ�����Ĺ�ľ������������ȴʲô��û"
                             "�У���$N" HIC "�۵ù�Ǻ��\n", me);
        }

        return 1;
}
