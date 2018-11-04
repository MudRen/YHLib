#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�Ƽ�");
        set("long", @LONG
�����������е�һ��СС�ľƼң��ط���Ȼ���󣬵���Ҳ
�в�����ң�ɵĵ��ӹ������������ҵ���ζ����Դ�ˣ���
�ſɿڵķ��ˣ����̲�סҲ���(order)һ���ˡ�
LONG);
        set("exits",([
                "north" : __DIR__"xiaodao2",
        ]));
        set("objects", ([
                CLASS_D("xiaoyao") + "/shiqingl": 1,
        ]));

        set("resource/water", 1);
        set("ricewater", 5);
        setup();
}

void init()
{
        add_action("do_order", "order");
}

int do_order(string arg)
{
        object me;
        object food;
        object water;

        me = this_player();

        if (arg)  return notify_fail(CYN "С�����ܳ�������������������û�а���\n" NOR);
        if (query("ricewater") > 0)
        {
                message_vision(CYN "С����������Ӧ��������һ�����ܳ�����\n" HIY "����"
                               "ʱ�������һ���׷���һ��ˮ���˸�$N" HIY "��\n" NOR, me);
                food = new(__DIR__"obj/rice");
                water = new(__DIR__"obj/bowl");
                food->move(me);
                water->move(me);
                add("ricewater", -1);
        }
        else 
                message_vision(CYN "С������������$N" CYN "Ǹ�������ԵĺȵĶ�û�ˡ�\n" NOR, me);

        return 1; 
}

void reset()
{
        ::reset();
        set("ricewater", 5);
}
