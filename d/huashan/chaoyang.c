// chaoyang.c

inherit ROOM;
#include <ansi.h>
// Modify by Rcwiz for Heros.cd
 
void create()
{
        set("short", "������");
        set("long", @LONG
������ǻ�ɽ�Ķ��壬Ҳ�Ƴ����壬�ǻ�ɽ���ճ��ľ��Ѵ���춴˸�
��ƺ����Զ������������С�·屳��ɽ�ӡ�С�·�����һСͤ������
���ߣ�ͤ�а���������һ�֣��Ǿ��ǻ�ɽ�����ġ���̨���ˡ�Զ��������
�£�ya���ϣ�����һ��������ӡ���ഫΪ��������项��ɽʱ�����µģ�
���ʫ�С�������������ɽ���鲨�����䶫��������ָ����ϹŴ�˵��
LONG );
        set("exits", ([ /* sizeof() == 1 */
           "westdown" : __DIR__"chaopath2",
        ]));


        set("item_desc", ([
           "ya"   : NOR + WHT "�������ͱڸ��ʣ�һ�����٣�teng��ֱ�����¡�\n" NOR,
           "teng" : HIG "һ�����٣�����la��ס����������֮�á�\n" NOR,
        ]));

        set("outdoors", "huashan" );

        setup();
}
 
void init()
{
        add_action("do_la", "la");
        add_action("do_jump", "jump");
}

int do_la(string arg)
{
        object me = this_player();

        if (! arg || arg != "teng")
               return notify_fail("��Ҫ��ʲô��\n");

        if (me->is_busy() || me->is_fighting())
               return notify_fail("����æ������˵�ɣ�\n");

        if (me->query_temp("la_teng_huashan"))
               return notify_fail("���Ѿ���ס�����ˡ�\n");

        message_vision(HIG "$N" HIG "���������ε�ץס�ˡ�\n", me);

        me->set_temp("la_teng_huashan", 1);

        me->start_busy(2);

        return 1;          
}

int do_jump(string arg)
{
        object me = this_player();

        if (! arg || arg != "ya")
               return notify_fail("��Ҫ���Ķ�����\n");

        if (me->is_busy() || me->is_fighting())
               return notify_fail("����æ������˵�ɣ�\n");

        if (! me->query_temp("la_teng_huashan"))
        {

               message_vision(HIM "$N" HIM "������������ ����\n", me);

               CHANNEL_D->do_channel(this_object(), "rumor", "��˵" + me->name() + HIM "��"
                                     "�»�ɽ���£���ɱ������\n" NOR); 

               me->die();               

        }

        message_vision(HIG "$N" HIG "���������������¡���\n", me);
                
        tell_object(me, HIG "��Ȼ�䣬�㷢��������һ��С��������һ�������������˽�ȥ��\n" NOR);

        me->move("/d/huashan/jinshedong");

        me->start_busy(2);

        return 1;          
}