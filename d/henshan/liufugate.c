#include <ansi.h>
inherit ROOM;

int do_knock(string arg);

void create()
{
        set("short", "��������");
        set("long",
"�������������š����������ˣ����Ǻ�ɽ���еĽ�������\n����Ī������"
"�ĵڶ�����������������ү�ӡ���������������\n�°ɣ�����(gate)���գ���"
"�ҼҶ�Ҳ�������ţ�Ī�ǽ������\nʲô���顣\n\n" HIR
"     ||                                        ||\n"
"  ���ԡԩ�" HIW "   ����������������������������" HIR "   ���ԡԩ�\n"
"  {------}" HIW "   ��                        ��" HIR "   {------}\n"
"  ���ԡԩ�" HIW "   ��       " HIY "��      ��" HIW "       ��" HIR "   ���ԡԩ�\n"
"   ������" HIW "    ��                        ��" HIR "    ������\n"
"   ������" HIW "    ����������������������������" HIR "    ������\n"
"   ������                                    ������\n\n"

); 
        set("exits", ([
                "south"  : __DIR__"hengyang1",
        ]));

        set("item_desc", ([
                "gate" : HIR "\n���Ĵ��Ž����ţ�����(knock)���ɡ�\n\n" NOR,
        ]));

        set("objects", ([
                __DIR__"npc/haoke"    : 4,
                __DIR__"npc/jian-ke" : 2,
        ]));  

        setup();
}
void init()
{
        add_action("do_knock", "knock");
        add_action("do_push", "push");
        add_action("do_push", "open");
}

int do_knock(string arg)
{
        object me;

        me = this_player();
              message_vision(HIW "\n$N���ˣ��ˣ��ˡ��������������ţ�������"
                             "ȴһ�㶯����û�С�\n\n" NOR, me);

        me->set_temp("marks/liufu",1);

        return 1;
}

int do_push(string arg)
{
    int n;
    object weapon,me = this_player();
    mapping fam;

    if ( !me->query_temp("marks")) 
              return notify_fail("�Źص����εģ����д򲻿���\n");

    if ( !arg || arg != "gate" ) 
              return notify_fail("���Ǹ��\n");

    message_vision(HIY "$N�ߵ���ǰ���������һ�ƣ���Ȼ���ƿ��˴��ţ�\n\n"NOR,me);

    set("exits/enter",__DIR__"liufudayuan");

    remove_call_out("close");
    call_out("close", 5, this_object());

    return 1;
}
void close_out()
{
    if (query("exits/enter")) 
              delete("exits/enter");
}

void close(object room)
{
    message("vision",HIC"\nһ������ѽѽ���죬�������˰Ѵ��Ÿ������ˡ�\n"NOR, room);

    room->delete("exits/enter");
}
