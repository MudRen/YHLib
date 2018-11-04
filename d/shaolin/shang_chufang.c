#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������̼ұ���Ժ�����һ�������ƽ���̼ҵĵ����Ƕ���
����Ե�������Ҫ (serve)Щʳ��������������һ�����ʦ
��æ����ͷ�󺹡��ݽǷ���һ����ˮ�ס�  
LONG);
	set("exits", ([
		"east"  : __DIR__"shang_houyuan",
	]));
        set("no_clean_up", 0);
        set("objects", ([
                __DIR__"npc/shang3" : 1,
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

        if (me->query("family/family_name") != "�̼ұ�")
                return notify_fail(CYN "��ʦ����һ�ɣ�˵�������ֲ����̼ұ��ģ��԰�ʳ����\n" NOR);

        if (present("tangcu liji", this_player())) 
                return notify_fail(CYN "��ʦüͷһ�壬˵�������������ã����˷�ʳ�\n" NOR);

        if (present("soup", this_object())) 
                return notify_fail(CYN "��ʦüͷһ�壬˵�������������ã����˷�ʳ�\n" NOR);

        if (query("ricewater") > 0)
        {
                message_vision(CYN "��ʦ���������ڵķ��˵ݵ������У�Ц"
                               "���������á�\n" NOR, me);
                food = new("/d/shaolin/obj/food");
                water = new("/d/shaolin/obj/soup");
                food->move(me);
                water->move(me);
                add("ricewater", -1);
        }
        else 
                message_vision(CYN "��ʦ��$N" CYN "Ǹ�������ˣ��ԵĺȵĶ�"
                               "û�ˡ�\n" NOR,me);
        return 1; 
}
