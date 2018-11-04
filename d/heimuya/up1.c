inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "����ƺ");
        set("long", @TEXT
�����ǰ�ɽ��һƬС��ƺ�����¶�����һ��·;���ɵ���
�Ѿ�û��·��ȥ����ǰ���羳����ͱڣ���ͷ�����������¶�
��ϡ������¥�������ɾ������������ƣ�����������
TEXT);

        set("exits", ([
                "eastdown" : __DIR__"shimen",
        ]));
        set("objects", ([
                CLASS_D("riyue") + "/feng" : 1,
        ]));
        setup();
}

void init()
{
        add_action("do_float", "float");
        add_action("do_float", "piao");
}

int do_float()
{
        object me;

        me = this_player();

        if (me->query_skill("juechen-shenfa", 1) < 180)
        {
                message_vision("$Nң��ɽ�£���˼���ã�̾�˿�����\n", me);
                return 1;
        }

        if (me->query("neili") < 100)
        {
                tell_object(me, "�������������������Ϣһ����˵�ɡ�\n");
                return 1;
        }

        me->add("neili", -80);

        message_sort(HIC "\n$N" HIC "��������һ���������һ�ɶ��𣬳�"
                     "ɽ����Ʈȥ��\n\n" NOR, me);

        me->move("/d/heimuya/shanya3");
        tell_object(me, "��˳���±�Ʈ���˺�ľ�¡�\n");
        message("vision", HIC "\n����һ����Х��Զ������" + me->name() +
                          HIC "˳���±�ƮȻ���ϣ��䶨���Ρ�\n" NOR,
                          environment(me), ({ me }));
        return 1;
}

