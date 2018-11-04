#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW "\n\n                ��     ��     ʥ     ��" NOR);
        set("long", HIW "\n
����һƬ����ɫ��ɭ�֣�����̵أ���Ҷ���졣һ��΢�����
�����������˵����⡣ɭ������һƬ�ž������������ݴ�����
��ĵ����Լ�ż�������ļ��������޵�˻����ɭ��������һ��
��Ȫ��" HIG "Ȫˮ" HIW "(" HIG "fountain" HIW ")��Ϊ��"
"�����ˣ�һ���ʺ������Ȫ֮�ϡ�\n��ֻ��������Χ����Ȫ����Ϸ��
\n" NOR);
        set("item_desc", ([
                "fountain" : HIG "Ȫˮ�������ԣ���Ϊ�峺���ˣ���"
                             "��������һ�ںȺȡ�\n" NOR,
        ]));
        set("objects", ([
                __DIR__"dujiaoshou" : 1,
        ]));
        set("no_fight", 1);
        set("sleep_room", 1);
        setup();
}

void init()
{
        add_action("drink", "drink");
}

int drink(string arg)
{
        object me = this_player();
        int exp, n, p;

        if (! arg || arg == "")
                return 0;

        if (arg == "fountain")
        {
                if (me->is_busy())
                {
                        return notify_fail("��Ķ�����û����ɣ������ƶ���\n");
                        return 1; 
                }

                if (me->query("sys/02.5.1"))
                {
                        message_vision(HIR "\n$N" HIR "˫�ָ�����Ȫˮ��ͻȻ��һ��"
                                       "˻������" HIW "���ǫF" HIR "һ�Ƕ��÷��˳�"
                                       "ȥ��\n\n" NOR, me);
                        me->move("/d/city/guangchang");
                        return 1; 
                }

                exp = me->query("combat_exp");

                if (exp >= 300000)
                        n = 50000;
                else
                if (exp >= 200000)
                        n = 30000;
                else
                if (exp >= 100000)
                        n = 10000;
                else
                if (exp >= 50000)
                        n = 5000;
                else
                if (exp >= 10000)
                        n = 3000;
                else
                        n = 0;

                p = n * 2 / 5;

                me->add("combat_exp", n);
                me->add("potential", p);
                me->set("sys/02.5.1", 1);
                message_vision(HIG "\n$N" HIG "˫������Ȫˮһ�����£�ֻ����ڸ���"
                               "�ޱȣ�˵����������ˬ�ڡ�\n" NOR, me);
                tell_object(me, HIC "������" + chinese_number(n) +
                                "�㾭�鼰" + chinese_number(p) +
                                "��Ǳ�ܵĲ�����\n" NOR);
                return 1;
        }
}
