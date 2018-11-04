#include <ansi.h> 

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǻ컨���ܶ��ڵĳ��������˵���ζ��ӯ��䡣����
�컨��ĳ�����ͷ�󺹣���æ��������������Ǻ컨��ĵ���
��������������Ҫ (serve)�㷹�ˣ����Ų��ᱻ�ܾ���
LONG);
        set("no_clean_up", 0);
        set("exits", ([
  		"west" : __DIR__"hh_guangchang",
	]));
        set("objects",([
                __DIR__"npc/honghua2" : 1,
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

        if (me->query("family/family_name") != "�컨��")
                return notify_fail(CYN "�컨���ӵ������ֲ��Ǻ컨��ģ��߿���\n" NOR);

        if (present("rice", this_player())) 
                return notify_fail(CYN "�컨���ӵ������������ã����˷�ʳ�\n" NOR);

        if (present("soup", this_object())) 
                return notify_fail(CYN "�컨���ӵ������������ã����˷�ʳ�\n" NOR);

        if (query("ricewater") > 0)
        {
                message_vision(CYN "�컨���ӽ��������ڵķ��˵ݵ������У�Ц"
                               "���������á�\n" NOR, me);
                food = new(__DIR__"obj/rice");
                water = new(__DIR__"obj/soup");
                food->move(me);
                water->move(me);
                add("ricewater", -1);
        }
        else 
                message_vision(CYN "�컨���Ӷ�$N" CYN "Ǹ�������ˣ��ԵĺȵĶ�"
                               "û�ˡ�\n" NOR,me);
        return 1; 
}
