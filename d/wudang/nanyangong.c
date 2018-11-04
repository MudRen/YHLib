#include <ansi.h>
inherit ROOM;

void close_andao();
string look_xiang();
int do_move(string arg);

void create()
{
        set("short","���ҹ�");
        set("long",@LONG
�����Ǿ����䵱ɽ���ҹ����˹���������֮�¡���������
���� (xiang)������������������������쾮�������Ծ�����
���������м���װ����Ŀ���䵱�������Ӵ���Ҵ��߹�������
��̨�������佣�󣬽������˶�����
LONG);
        set("exits", ([
          	"out"    : __DIR__"shizhu",
          	"southup": __DIR__"gaotai",
      	]));
      	set("item_desc",([
          	"��������" : (: look_xiang :),
          	"xiang"    : (: look_xiang :),
      	]));
      	set("no_clean_up", 0);
      	setup();
}

int valid_leave(object ob, string dir)
{
        mapping myfam;

        ob = this_player();
        myfam = (mapping)ob->query("family");

        if ((int)ob->query("combat_exp", 1) < 10000 &&
           (dir == "southup"))
            	return notify_fail(HIY "��������佣������̫���㱻"
                                   "�����ĵ���������ȥ��\n");

        if ((! myfam || (myfam["family_name"] != "�䵱��")) &&
           (dir == "southup"))
            	return notify_fail(HIY "��������佣������̫���㱻"
                                   "�����ĵ������˻�����\n");
        return 1;
}

void init()
{
        add_action("do_move", "move");
}

string look_xiang()
{
        return YEL "��������ͭ��ͣ����Դ��𣬹������ֻ�Ǻ�����"
               "������ڵò��������롣\n" NOR;
}

int do_move(string arg)
{
        object room, ob;

        ob = this_player();

        if (! arg || arg != "xiang" )
		return notify_fail("��Ҫ�ƶ�ʲô��\n");

        message_sort(HIY "\n$N" HIY "�ߵ��������񱳺�����ʹ��������"
                     "�������������ţ������������ˡ�����¶��һ����"
                     "��������ʯ��������ȥ�����������ͨ��һ��������"
                     "\n\n" NOR, ob);
        set("exits/down", __DIR__"nanyan0");

        if (room = find_object(__DIR__"nanyan0"))
        {
        	room->set("exits/up", __FILE__);
           	message("vision", HIY "\n�컨���Ȼ����������������"
                        "¶��һ�����ϵ�¥�ݡ�\n" NOR, room );
        }
        remove_call_out("close_andao");
        call_out("close_andao", 3);
        return 1;
}

void close_andao()
{
    	object room;
        int i;

        if (! query("exits/down")) return;
    		message("vision", HIY "\nֻ��ƹ��һ���죬�Ͼ����Զ�"
                        "�ƻ�ԭ����\n" NOR, this_object());

    	if (room = find_object(__DIR__"nanyan0"))
    	{
        	message("vision", HIY "\nֻ��ƹ��һ���죬���ϵĶ���"
                        "�Զ�����ʵʵ�ع���������\n" NOR, room);
    	}
    	delete("exits/down");
}
