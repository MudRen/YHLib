#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����һ����ĳ�����������Ŵ�Բ������Χ����ż�����
�Ρ����ڻ����ż���ˮ�ɻ���������һ�±��ӣ����㡣Ҳ��֪
�ǻ��㻹�Ƿ��㡣ƽʱ�һ����ĵ��Ӻ����˶��������ò͡���
�ſɿڵķ��ˣ����̲�סҲ���(serve)һ�ݡ�
LONG);
        set("exits",([
                "east" :__DIR__"qianyuan",
        ]));

        set("objects", ([
                __DIR__"npc/cheng" : 1,
                __DIR__"npc/yapu" : 1,
        ]));
        set("ricewater", 5);
        set("resource/water", 1);
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

        if (me->query("family/family_name") != "�һ���")
                return notify_fail(CYN "��Ӣ΢Ц��˵�����Բ����㲻�ǵ���"
                                   "�ĵ��ӣ��Ҳ��ܹ�����\n" NOR);

        if (present("gao", this_player())) 
                return notify_fail(CYN "��ӢЦ�Ŷ���˵����ι�������������"
                                   "ѽ���ɱ��˷�ʳ�\n" NOR);

        if (present("zuixian cha", this_object())) 
                return notify_fail(CYN "��ӢЦ�Ŷ���˵����ι�������������"
                                   "ѽ���ɱ��˷�ʳ�\n" NOR);

        if (query("ricewater") > 0)
        {
                message_vision(CYN "��Ӣ���������ڵķ��˵ݵ�$N" CYN "����"
                               "��Ц���������á�\n" NOR, me);
                food = new("/d/taohua/obj/gao");
                water = new("/d/taohua/obj/cha");
                food->move(me);
                water->move(me);
                add("ricewater", -1);
        }
        else 
                message_vision(CYN "��Ӣ��$N" CYN "Ǹ�������Բ��𣬳Եĺ�"
                               "�Ķ�û�ˡ�\n" NOR, me);
        return 1; 
}
