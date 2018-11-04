#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIR "�� �� �� ��" NOR);
        set("long", HIR @LONG

                       ��            ��

    �����������������������������ǰ��һ���޵���Ԩ����Ԩ��
��������һ��Ѫ��ɫ�ľ޴���(jingti)��ʱ��ʱ����ɢ����������Ѫ
��ɫ��â��Ͷ����˿˿������Ҳ����ʹ�˵�еġ�����Ѫ�����ɡ�

LONG NOR );
        set("exits", ([
                "up" : __DIR__"diyin_road2",
        ]) );

        set("item_desc", ([
                "jingti" : RED "һ��Ѫ��ɫ�ľ޴��壬����Ѫɫ��"
                           "â�����̲�ס����(qiao)һ��������\n" NOR,
        ]));

        set("no_sleep_room", 1);

        setup();
}

void init()
{
        add_action("do_qiao", "qiao");
}

int do_qiao(string arg)
{
        object me = this_player();
        object ob;

        if( (!arg) || !((arg == "jingti") || (arg == "����")))
                return notify_fail("��Ҫ��ʲô��\n");

        message_vision(HIW "\n$N" HIW "һԾ���𣬷���һ������Ѫ��ɫ����һ�ࡣ\n" NOR, me);
 
        if(query("not_xuemai") || me->query("combat_exp") < 1500000 )
        {
                message("vission", HIY "���Ǿ���ֻ����΢�Ļζ���һ�£���û������Ӧ��\n" NOR, me);
                return 1;
        }
        ob = new(__DIR__"obj/diyin");
        ob->move( environment(me) );
        message_vision(HIR "ֻ���������𣬡����꡹һ����һС�龧����Ƭ�����˵��ϡ�\n" NOR, me);
        set("not_xuemai", 1);
        remove_call_out("regenerate"); 
        call_out("regenerate", 86400);
        return 1;
}

int regenerate()
{
        set("not_xuemai", 0);
        return 1;
} 

