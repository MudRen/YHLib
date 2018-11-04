#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
������ȫ��̵����ã��ǵ������ò͵ĵط�������úܴ�
����ذڷ���һ��һ�ŵ����Ρ�������������������������ȫ
����ӣ��е������òͣ��еĵ�ͷ̸Ц�����ſɿڵķ��ˣ���
�̲�סҲ���(serve)һ�ݡ�
LONG);
        set("exits",([
                "north" : __DIR__"xiuxishi",
                "east" : __DIR__"chufang",
                "northwest" : __DIR__"wuchang2",
        ]));
        set("objects", ([
                __DIR__"npc/huogong" : 1,
        ]));
        set("ricewater", 5);
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_serve", "serve");
}

int do_serve()
{
        object me;
        object food;
        object water;
        me = this_player();

        if (me->query("family/family_name") != "ȫ���")
                return notify_fail(CYN "�𹤵��˴���һ�ɣ�˵�������������ģ���"
                                   "���췹�ԣ�\n" NOR);

        if (present("rice", this_player())) 
                return notify_fail(CYN "�𹤵���üͷһ�壬˵�������������ã���"
                                   "�˷�ʳ�\n" NOR);

        if (present("wan", this_object())) 
                return notify_fail(CYN "�𹤵���üͷһ�壬˵�������������ã���"
                                   "�˷�ʳ�\n" NOR);

        if (query("ricewater") > 0)
        {
                message_vision(CYN "�𹤵��˽��������ڵķ��˵ݵ������У�Ц"
                               "���������á�\n" NOR, me);
                food = new(__DIR__"obj/rice");
                water = new(__DIR__"obj/bowl");
                food->move(me);
                water->move(me);
                add("ricewater", -1);
        }
        else 
                message_vision(CYN "�𹤵��˶�$N" CYN "Ǹ�������ˣ��ԵĺȵĶ�"
                               "û�ˡ�\n" NOR,me);
        return 1; 
}
