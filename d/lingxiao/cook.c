inherit ROOM;

#include <ansi.h> 

void create()
{
        set("short","����");
        set("long",@LONG
�����������ǵĳ�����һ�󷹲˵���ζ��ӯ��䡣һ������
������ͷ�󺹣�����������������������Ҳ�ر��˰���һ����
���������ϣ���һ�����Ĳ���������һ�ڼ���Ĺ�����˵�ǰ�
����ȥ�����¿��������Ҫ��ÿһ����ֵ�����ĵ��Ӷ�Ҫ����
�ɣ������������ơ����������(serve)������÷��ˡ�
LONG);
        set("exits",([
                "west" : __DIR__"zoulang2",
        ]));
        set("objects",([
                __DIR__"npc/dizi" : 1,
        ]));
        set("ricewater", 5);
        setup();
}

void init()
{
        add_action("do_serve","serve");
}

int do_serve()
{
        object me;
        object food;
        object water;
        me = this_player();

        if (me->query("family/family_name") != "������")
                return notify_fail(CYN "�������ӵ������ֲ��������ǵģ��߿���\n" NOR);

        if (present("rice", this_player())) 
                return notify_fail(CYN "�������ӵ������������ã����˷�ʳ�\n" NOR);

        if (present("soup", this_object())) 
                return notify_fail(CYN "�������ӵ������������ã����˷�ʳ�\n" NOR);

        if (query("ricewater") > 0)
        {
                message_vision(CYN "�������ӽ��������ڵķ��˵ݵ������У�Ц"
                               "���������á�\n" NOR, me);
                food = new(__DIR__"obj/rice");
                water = new(__DIR__"obj/soup");
                food->move(me);
                water->move(me);
                add("ricewater", -1);
        }
        else 
                message_vision(CYN "�������Ӷ�$N" CYN "Ǹ�������ˣ��ԵĺȵĶ�"
                               "û�ˡ�\n" NOR,me);
        return 1; 
}

