#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
��������Ů��ɽ�µĶ���ɽ�£���ǰ�ߵ�ɽ�±Ƚ�Զ��������Ҫ����
ȥ�������ס�
LONG );
        set("outdoors", "huashan");
        setup();
}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb()
{
        object me = this_player();
        int n = me->query_skill("dodge", 1);

        message_vision( HIY "$N" HIY "������һ��������������ɽ������"
                        "����\n" NOR, this_player());
        if (n > 100)
        {
                message_vision(HIC "$N" HIC "���˰��죬����ϥ�Ƕ���"
                               "����ʯ�����Ѫ���죬���������������"
                               "ɽ�¡�\n" NOR, this_player());

                me->move(__DIR__"kuihua_1");

                message_vision(HIC "$N" HIC "�������ɽ����������"
                        "��\n" NOR, this_player());
        } else
        {
                message_vision(HIR "$N" HIR "����һ�ᣬһ��������"
                               "������ȥ��\n" NOR, this_player());
                me->unconcious();
        }
        return 1;
}
