#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIB "����ˮ��̶��" NOR);
        set("long", HIB @LONG

                    ��     ˮ     ��     ̶

    ���������˾�ı�ˮ��̶����˵������֮�׵�����������û�ڴ�̶
�С�̶�б�ˮ���İ��ޱȣ������ƺ��м������ڣ���ʵ�ڿ�������ͨ��
�δ���ˮ�б���̹ǣ������������ܣ���ֻ����������һ��һ����ʧ��


LONG NOR );

        set("exits", ([
                "east" : __DIR__"hantan1",
                "west" : __DIR__"hantan1",
                "south" :__DIR__"hantan1",
                "north" :__DIR__"hantan2",
        ]));
        set("no_clean_up", 0);
        setup();
}

void init()
{
        object me;
        int meqi, meneili, decqi, mq;
        me = this_player();

        if ( present("diyin xuemai", me))
        {
                tell_object(me, RED "�㻳�еĵ���Ѫ������һ������������ס�������"
                                "������\n" NOR);
                return 0;
        }
        tell_object(me, HIW "�����ݱ�ˮ��̶��̶�к�������ιǣ���"
                        "ֻ������ѪҺ������סһ�㣡\n" NOR);
        meqi = (int)me->query("qi");
        meneili = (int)me->query("neili");
        mq = (int)me->query("max_qi");
        decqi = (int)( mq / (random(4) + 5 + meneili/200) );
        meqi = meqi - decqi;
        me->set("neili", 0);

        if(meqi > 0)
        {
                me->set("qi", meqi);
        }
   else {
                me->set_temp("die_reason", "�ڱ�ˮ��̶��������");
                me->die();
        }
        return 0;
}
