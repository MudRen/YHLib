#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��Į��ɳ");
        set("long", @LONG
�㴦�ڿ������¯��ɳĮ�У��ȵ�����������͸��������
�����������ķ���ʲôҲ���������������۹����ķ�ɳʲôҲ
����������ؼ�·�ֻʣ����һ���ˡ�����»�����������ɳ
�������ı����ĸо���
LONG);
        set("outdoors", "gaochang");
        set("exits", ([
                "east" : __DIR__"shamo2",
                "west" : __DIR__"lvzhou",
	]));
        setup();        
}

void init()
{
        object me = this_player();

        if (userp(me))
                call_out("kill_user", 1, me);
}

int kill_user(object me)
{
        object ob;

        if (! me || environment(me) != this_object())
		return 1;

        if (! present("tu ying", this_object()))
        {
    		message("vision", HIR "\nͻȻ�䣬ֻ��һ����Ӱ����"
                                  "������\n" NOR, this_object());

                ob = new("clone/quarry/ying");
                ob->move(this_object());
                ob->kill_ob(me);
        }
}

int valid_leave(object me, string dir)
{
        int current_water;
        current_water = me->query("water");

        if (userp(me) && current_water == 0)
        {
                write(HIY "���Ѿ��е��첻���ˣ�ڤڤ�о������˰���"
                      "̧�����ſ�ջ��\n" NOR);
                me->unconcious();
                me->move(__DIR__"longmen");
        } else

        if (current_water > 0 && current_water < 20)
        {
               write(HIR "�����ȱˮ���ʵ���ð���ǡ�\n" NOR);
               me->set("water", 0);
        }

        if (current_water >= 20)
               me->add("water", -20);

        return 1;
}
