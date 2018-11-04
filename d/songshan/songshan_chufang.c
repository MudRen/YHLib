#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǻ�ɽ�ɳ��ȶ������һ�������ƽ����ɽ�ĵ�����
���˱���Ե�������Ҫ(serve)Щʳ��ԡ��������������һ
����ʦ��æ����ͷ�󺹡��ݽǷ���һ����ˮ�ס�  
LONG);
	set("exits", ([
  	       "north" : __DIR__"changlang",
	]));
	
        set("objects", ([
                __DIR__"npc/chushi" : 1,
        ]));

        set("ricewater", 5);

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

        if (me->query("family/family_name") != "��ɽ��")
                return notify_fail(CYN "��ʦ����һ�ɣ�˵�������ֲ�����ɽ�ɵģ��԰�ʳ����\n" NOR);

        if (present("man tou", this_player())) 
                return notify_fail(CYN "��ʦüͷһ�壬˵�������������ã����˷�ʳ�\n" NOR);

        if (present("water", this_object())) 
                return notify_fail(CYN "��ʦüͷһ�壬˵�������������ã����˷�ʳ�\n" NOR);

        if (query("ricewater") > 0)
        {
                message_vision(CYN "��ʦ��һ����ͷ��һ����ˮ�ݵ�$N���У�Ц"
                               "���������á�\n" NOR, me);
         
                food = new("/d/henshan/obj/mantou");
                water = new("/d/henshan/obj/water");
                food->move(me);
                water->move(me);
                add("ricewater", -1);
        }
        else 
                message_vision(CYN "��ʦ��$N" CYN "Ǹ�������ˣ��ԵĺȵĶ�"
                               "û�ˡ�\n" NOR,me);
        return 1; 
}
