#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "����ɽ");
        set("long", @LONG
����ɽ��ɽ�� (cliff)������ʮ�ֶ��ͣ�ɽ�����Ͼ�û��
ãã�ƺ����嶥�����ѩ��ɽ������ȴ�������Բԣ���ľï��
���Ž��أ�����������
LONG);
        set("outdoors", "kunlun");

        set("exits", ([
                "enter" : __DIR__"houyuan",
                "northeast" : __DIR__"bainiushan",
        ]));

        set("item_desc", ([
                "cliff" : "����ɽɽ�ں��Ƕ��ͣ�������Ҫ����(climb)��ȥ�������ס�\n",
        ]));

        set("no_clean_up",0);
        create_door("enter", "С��", "out", DOOR_CLOSED);
        setup();
}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb()
{
        object me = this_player();

        message_vision(HIY "$N" HIY "������һ������������ɽ�±�ȥ��\n" NOR, me);

        if (random(me->query_skill("dodge", 1)) <= 30)
        {
                me->receive_damage("qi", 50);
                me->receive_wound("qi", 50);
                message_vision(HIR "ֻ��$N" HIR "һ��С�Ľ���̤�գ�ˤ��������\n" NOR, me);
                me->move(__DIR__"fufengshan");
                tell_object(me, HIR "���ɽ�Ϲ���������ֻ���û�����ʹ�ޱȣ������˼����ˡ�\n" NOR);

                message("vision", HIR "ֻ��" + me->query("name") + HIR "��ɽ�Ϲ�µµ�ع���"
                                  "���������ڵ��ϰ�������������\n" NOR, environment(me), ({me}));
                return 1;
        }
        message("vision", HIY + me->name() + HIY "��һ������������������£�����ɽȥ��\n",
                          environment(me), ({me}) );
        me->move(__DIR__"sanshengao");

        message_vision(HIY "$N" HIY "������ķ���ɽɽ������������\n" NOR, me);

        return 1;
}
