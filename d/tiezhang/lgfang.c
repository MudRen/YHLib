#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIC "������" NOR);
        set("long", @LONG
����һ���û��������ɵ�ʯ�ݡ�����һֻ��¯��ȼ�˺�̿������������
�ڵ�һ�� (huo)������������������Сͯ��һ��ʹ���������䣬��һ������
����������֮�����ɳɳ֮����������������ɳ���������е��ӱ�Ŀ��ϥ
���ڹ�ǰ����������ϵ��������ţ�������Ʋ���(charu)���п����Ʒ���
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"guangchang",
        ]));

        set("objects",([
                __DIR__"npc/heiyi" : 1,
        ]));

        set("item_desc", ([
                "huo" : HIR "\n����һ�ھ޴������������ʢ����ɳ������ȼ��̿��\n" NOR,
        ]));

        setup();
}

void init()
{
        add_action("do_cha", "charu");
}

int do_cha(string arg)
{       
        mapping fam;
        object me;
        me = this_player();

        if ( ! living(me)) return 0;
        if ( ! living(this_player()) || arg != "huo" )
        {
                write("�������Ķ���ѽ��\n");
                return 1;
        }

        if( me->is_busy() )
                return notify_fail("��������æ���ء�\n");

        if ( (int)me->query_skill("strike", 1) < 30 )
                return notify_fail("�㽫˫�ֲ������У����ȵ���ɳ��ʱ�̵���ֽв�ֹ���������ǰ��Ʒ����ߵ������ɡ�\n");

        if ( (int)me->query_skill("strike", 1) > 100)
                return notify_fail("�㽫˫�ֲ������У���������ɳ��ϰ��˿����߲�������Ʒ��ˡ�\n");

        if (! me->can_improve_skill("strike"))
                return notify_fail("���ʵս���鲻�����޷��ټ�������Ʒ���\n");

        if((int)me->query("qi") < 40)
        {
                write("�����һ������ֱ�������������ѵ���������Ϣһ���ٽ������ɣ�\n");
                return 1;
        }

        me->receive_damage("qi", 30);
        me->improve_skill("strike", me->query("con") * 2);
        me->start_busy(random(2));
        message_vision(HIR "\n$N" HIR "��˫�ֲ�����е���ɳ�\n" NOR, me);
        write(RED "���ȵ���ɳ�����˫���̵�ͨ�죬�����˫�ֵ�ʱ��ø���ǿ׳�����ˡ�\n" NOR);
        return 1;
}
