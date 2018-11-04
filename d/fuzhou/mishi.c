#include <ansi.h>
#include <room.h>
inherit ROOM;

string look_hua();
string look_liang();
int valid_leave();

void create()
{ 
       set("short", "��");
       set("long", @LONG
����������լ��Ժ��һ��С�񷿣������ﲼ������������
�����ǻҳ����������Ѿ��ܾ�û���˴�ɨ�ˡ������ǽ������
���������״�������һ����(hua)�����䴦б���ż����ɲ�
LONG);
        set("exits", ([
                "east" : __DIR__"houyuan",
        ]));       
        set("item_desc", ([
                "hua"     : (: look_hua :),
                "liang"   : (: look_liang :),
        ]) );
        set("objects", ([
                "/d/wudu/obj/ganchai" : 2,
        ]));
        setup();
}

void init()
{
        add_action("do_jump", "jump");
}

string look_hua()
{
        object me = this_player();

        if (me->query("score") < 1000)
                return HIR "\nһ���¾ɵĻ����������Ǵ�Ħ���棬û��ʲô��ͬ��\n" NOR;

        if (me->query("score") < 3000)
                return HIR "\nһ���¾ɵĻ������д�Ħ���������ո����������鰲�͡�\n" NOR;

        me->set_temp("marks/��1", 1);
        return HIR "\nһ���¾ɵĻ������д�Ħ���������ո���������ָ����(liang)����\n" NOR;
}

string look_liang()
{
        object me = this_player();

        if (! me->query_temp("marks/��1"))
                return "��Ҫ��ʲô��\n";

        if (query("move"))
                return WHT "һ���ľ���ķ�����������ո�µĹκۣ��ƺ�����ǰ�����˶�����\n" NOR;

        me->set_temp("marks/��2", 1);
        return WHT "һ���ľ���ķ�������ϧ���̫�ã��Ѿ����õò��������ˡ�\n" NOR;
}

int do_jump(string arg)
{
        object ob, me = this_player();

        if (! arg || arg != "liang")
		return 0;

        if (me->query_temp("marks/��2"))
        {
	        if (me->query_dex() < 40) 
                	write(HIC "����ͼ���Ϸ������������������ݣ�ֻ�����ա�\n" NOR);
                else
                {
        		foreach (ob in deep_inventory(me)) if (ob->is_character())
        		{
                		ob->move(environment(me));
                		message_vision("\n$N��" + ob->name() + "�ӱ��Ϸ�������"
                                               "�����ڵ��ϡ�\n\n" NOR, me);
        		}

                        message("vision", HIY "ֻ��" + me->name() + HIY "һ����Ծ���˷�"
                                          "����\n" NOR, environment(me), me);
                        set("move", 1);
                        write(HIY "\n����������һԾ�������˷�����\n\n" NOR);
                        me->move(__DIR__"liang");
                        message("vision", HIY "ֻ��" + me->name() + HIY "������Ĳ�Ծ"
                                          "��������\n" NOR, environment(me), me);
        	}
                return 1;
        }
        write("ʲô��\n");

        return 1;
}

int valid_leave(object me, string dir)
{
        me->delete_temp("marks/��1");
        me->delete_temp("marks/��2");
        return ::valid_leave(me, dir);
}
