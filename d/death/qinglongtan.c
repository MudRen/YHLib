#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN "����������" NOR);
        set("long", GRN @LONG

                    ��         ��         ��

    ��������˾��ˮ��̶�����һ����Ѩ�������ϲ��տ�����������
�Ŀ����������ڿ��Ի����ˡ���˵������֮�׵���������Ϣ�ڴ˵ء���
���İ��ޱȣ����������������Χ���������׷Ѱ(xun) ����������
Ӱ��̶ˮ����̹ǣ������������ܣ���ֻ����������һ��һ����ʧ����
Ѩ���һ�������ĺ����γ���һ����������������(xuanwo)��

LONG NOR );

        set("objects", ([
                __DIR__"obj/shuizao" : 1,
        ]));

        set("item_desc", ([
                "xuanwo" : HIW "\nһ���ɺ����γɵ����У����ƺ�"
                           "����ͨ�����ص����档\n" NOR,
        ]));

        set("qinglong", 1);
        setup();
}

void init()
{
        object me;
        int meqi, meneili, decqi, mq;
        me = this_player();

        add_action("do_move", "enter");
        add_action("do_xun", "xun");

        if (me->query("id") == "qing long"
           || present("diyin xuemai", me))
        {
                tell_object(me, RED "�㻳�еĵ���Ѫ������һ������"
                                "������ס������ľ�����\n" NOR);
                return 0;
        }
        tell_object(me, HIW "�����ݱ�ˮ��̶��̶�к�������ιǣ���"
                                "ֻ������ѪҺ������סһ�㣡\n" NOR);
        me->set_temp("die_reason", "�ڱ�ˮ��̶��������");
        me->die();
        return 0;
}

int do_xun(string arg)
{
        object me = this_player();
        object ob;
        object ob1;

        if (objectp(present("qing long", environment(me))))
                return notify_fail("�����Ѿ������ˣ���Ѱʲôѽ���Ͽ�ս���ɣ�\n");

        if (query("qinglong") < 1)
                return notify_fail("�����Ѿ������ˣ�������ôѰҲ��Ѱ�����ģ�\n");

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");
       
        if ((int)me->query("jing") < 100)
                return notify_fail("��̫���ˣ���΢��Ϣһ�°ɡ�\n");

        if ((int)me->query("qi") < 100)
                return notify_fail("��̫���ˣ���΢��Ϣһ�°ɡ�\n");

        message_vision(HIC "\n$N" HIC "�ڶ����Ĵ����ߣ����Ź������"
                       "˿������ϸ����Ѱ�Ŷ�Ѩ�ڵ�һ�С�\n" NOR, me); 
        remove_call_out("xun"); 
        call_out("xun", 5, me);
        me->start_busy(5);
        return 1;
}
 
int xun(object me)
{ 
        object ob;
        object ob1;
        if (random(10) < 6)
        {
                me->receive_damage("jing", 50 + random(50));
                me->receive_damage("qi", 50 + random(50));
                me->start_busy(5);
                message_vision(WHT "$N" WHT "Ѱ���˰��죬����û������"
                               "����û�ļ���һ������Ҳ�ﲻס����æ"
                               "�ε������ϲ�������\n" NOR, me);
                return 1;
        }

        if (random(10) < 5)
        {
                me->receive_damage("jing", 50 + random(50));
                me->receive_damage("qi", 50 + random(50));
                me->start_busy(5);
                message_vision(HIY "���$N" HIY "һת��˫�Ų�С�ı�"
                              "�ұ��������ˮ���ס�����˺ô󾢲�����"
                              "����\n" NOR, me);
                return 1;
        }

   else if (random(10) < 4) 
        {         
                me->receive_damage("jing", 300 + random(50));
                me->receive_damage("qi", 300 + random(50));
                me->receive_wound("jing", 200 + random(50));
                me->receive_wound("qi", 200 + random(50));
                me->start_busy(5);
                message_vision(HIR "���$N" HIR "��ת����ʱ�����顱��һ"
                               "����ͷײ���˼�ͻ���ұ��ϣ���ʱ��Ѫ�ɽ���"
                               "ʹ��$N" HIR "���໡��ֽв�ֹ��\n"
                               NOR, me);
                return 1;
        }

   else { 
                ob = new("/d/death/npc/qinglong");
                ob->move("/d/death/qinglongtan");
                add("qinglong", -1);
                message_vision(HIW "\n\nֻ����Ѩ��������춯�ص�һ��"
                                   "ŭ�������������������������Ĥ����"
                                   "��\nʹ������Χ�ı�̶��ˮ���پ���"
                                   "�������첨�ˣ���ǰһ����һ����Ȼ��"
                                   "��\n����������ǰ��������֮�׵�����"
                                   "���������ˡ�\n\n" NOR, me); 
                return 1;
        }
       
}

int do_move(string arg)
{
        object paper,
        me = this_player();

        if (! arg || arg == "")
                return 0;

        if (arg == "xuanwo")
        {
                if ( objectp(present("qing long", environment(me))))
                {
                        write(HIW "\n����һ��ŭ������βֱɨ��������������"
                              "���Ե��ұ��ϣ�ʯм��������ס��ȥ·��\n" NOR);
                        return 1;
                }
                message_vision(HIW "\n$N" HIW "��һ���������˺������С���\n"
                               NOR, me);
                me->move("/d/death/qiao1");
                message_vision(HIW "\nֻ��$N" HIW "���κ����µĺ��������׵���"
                                   "�У�Ȼ�����صĵ������κ����ϡ�\n" NOR, me);
                me->set("neili", 0);
                me->set("jingli", 0);
                me->set("qi", 10);
                me->set("eff_qi", 10);
                me->set("jing", 10);
                me->set("eff_jing", 10);
                tell_object(me, HIR "�㱻����ͷ��Ŀ�����������������ۡ������"
                                "һ�����Ѫ��\n" NOR);
                destruct(present("diyin xuemai", me));
                tell_object(me, HIC "\n�㻳�е�" NOR + RED "����Ѫ��" NOR +
                                HIC "�ľ���Դ��������һ������Ʈ����\n" NOR);
                return 1;
        }
        return 0;
}
