#include <ansi.h> 
inherit ROOM;

void init();
int close_gate();
int do_open();
int valid_leave();
string look_gate();

void create()
{
    	set("short", "�㳡");
    	set("long", @LONG
������������ǰ�Ĺ㳡�������㳡�ɴ�����ʯ�̳ɣ���Ϊ
ƽ̹�����������Զ������Щ���𡣴Դ�С�ݴ�ʯ��ķ�϶�г�
�˳������㳡����Χ�������ܵ������֣��Ľ��ϸ����˼���ʯ����
�ּ�����Ϊģ������ǰ����ǽ���ߣ��������ݣ�����һ��������
���������ߵ����ɼľ��ͭ����(gate)���Ϸ�һ����ң�����
��������š������¡��������֡���ǰ����������վ�ż���ɮ�ˡ�
LONG );
    	set("exits", ([
        	"east" : __DIR__"guangchang1e",
        	"south" : __DIR__"shijie11",
        	"west" : __DIR__"guangchang1w",
    	]));

    	set("outdoors", "shaolin");
   	set("item_desc",([
        	"gate"        :    (: look_gate :),
    	]));

    	set("objects",([
        	CLASS_D("shaolin") + "/qing-fa" : 1,
    	]));

    	setup();
    	"/clone/board/shaolin_b"->foo();
}


/* TODO
 �˴���Ϊ��(knock gate) ���ź�һɮ��Ӧ���򿪴��ţ�
��֨����һ�������Ŵ��˿�����һλ׳��ɮ���������´�������
���������������� һ�ᣬ
����Ϊ����ɮ�ˣ����������������߻��������������ÿ���˵����ʦ�������ˣ������
����Ϊ����ɮ�ˣ����񽵵ͻ��и��񣩳���������˵��������Ժ������ʹ��ʦ��ʦ�ֻ�
����������������������������������������������������ȥ����Ժ�������й�����
������������������������������������ֱ���ͽ�����Ժ���β��ʺ󣬴���ɮ���Ѻ����
����Ǳ���ɮ�ˣ����ԣ�������˵������λʩ����ذգ����²��Ӵ����ˡ�
����Ǳ���ɮ�ˣ�Ů�ԣ�������˵������λŮʩ��������ذգ����´Ӳ��Ӵ�Ů�͡�
����Ǳ���ɮ�ˣ�������Ů���и�����ʱ������ֿ��һ��ѩ���Ľ䵶���������λε�
���������������������������������������׼����ؿڣ���üŭĿ��˵�������аħ
����������������������������������������������ҹ������Ժ��ٸ��߽�����һ����
��������������������������������������ʱ��ն�����ǵĹ��ȣ�
�Բ����׼ҵ��Ӳ�����������
*/

void init()
{
    	add_action("do_knock", "knock");
}

int close_gate()
{
    	object room;

    	if (! (room = find_object(__DIR__"smdian")))
        	room = load_object(__DIR__"smdian");

    	if (objectp(room))
    	{
        	delete("exits/north");
        	message("vision", HIY "ֻ��ƹ��һ�����������˰Ѵ��Ź����ˡ�\n" NOR,
            			  this_object());

        	room->delete("exits/south");
        	if (objectp(present("qingfa biqiu", room)))
            		message("vision", CYN "�巨������ǰ�Ѵ��Ź���������\n" NOR, room);
        	else
            		message("vision", CYN "׳��ɮ����ǰ�Ѵ��Ź���������\n" NOR, room);
    	} else
		message("vision", "ERROR: gate not found(close).\n", room);

    	return 1;
}

int do_knock(string arg)
{
    	object room;

    	if (query("exits/north"))
        	return notify_fail("�����Ѿ��ǿ����ˡ�\n");

    	if (! arg || (arg != "gate" && arg != "north"))
        	return notify_fail("��Ҫ��ʲô��\n");

    	if (! (room = find_object(__DIR__"smdian")))
        	room = load_object(__DIR__"smdian");

    	if (objectp(room))
    	{
        	set("exits/north", __DIR__"smdian");
        	message_vision(HIY "$N" HIY "������������ţ�ֻ��֨��"
                               "һ������λ׳��ɮ��Ӧ���򿪴��š�\n" NOR,
                               this_player());

        	room->set("exits/south", __FILE__);
        	message("vision", HIY "���洫��һ����������׳��ɮ��Ӧ"
                                  "����ǰ�Ѵ��ſ���\n" NOR, room);
        	remove_call_out("close_gate");
        	call_out("close_gate", 10);
    	}
    	return 1;
}

int valid_leave(object me, string dir)
{
    	if (dir != "north")
        	return ::valid_leave(me, dir);

    	if (! ::valid_leave(me, dir))
        	return 0;

    	if ((me->query("family/family_name") == "������"))
    	{
        	if (me->query("class") != "bonze")
        	{
            		return notify_fail(CYN "׳��ɮ��˵�����Բ����׼ҵ��Ӳ���"
                                           "�������С�\n" NOR);
        	}

        	if (((int)me->query("guilty") == 0) &&
	    	(me->query("combat/K_record") == me->query("combat/WPK")))
        	{
            		write(CYN "׳��ɮ�˲����ÿ���˵����ʦ�������ˣ������\n" NOR);
            		return 1;
        	} else
        	{
            		if (me->query("guilty") == 0)
            		{
                		if (me->query("combat/shen_record") > (int)me->query("shen"))
                    			me->set("guilty", 1);
           	     		else
                    			me->set("guilty", 2);
                		me->set("combat/K_record", me->query("combat/WPK"));
                		me->set("combat/shen_record", me->query("shen"));
	        	}

            		me->move(__DIR__"smdian");
            		write(CYN "׳��ɮ�˳���������˵��������Ժ������ʹ��ʦ��ʦ��ȥ����Ժ"
                           	  "�������й�����\n" NOR);
	    		return -1;
        	}
    	} else
	if (present("yingxiong ling", me))
    	{
        	write(CYN "׳��ɮ�˺�ʮΪ�񣬲����ÿ���˵����ԭ���ǹ�ͼݵ�����������\n" NOR);
        	return 1;
    	}
    
    	if (me->query("shen") >= 0)
    	{
        	if (me->query("gender") == "Ů��")
        	{
            		return notify_fail(CYN "׳��ɮ��˵������λŮʩ��������ذգ�����"
                                           "�Ӳ��Ӵ�Ů�͡�\n" NOR);
        	} else
        	{
            		return notify_fail(CYN "׳��ɮ��˵������λʩ����ذգ����²��Ӵ�"
                                           "���ˡ�\n" NOR);
        	}
    	}
    	return notify_fail(HIR "׳��ɮ����ʱ������ֿ��һ��ѩ���Ľ䵶���������λεĵ����"
                           "׼���\n�ؿڣ���üŭĿ��˵���������аħ������������ҹ�����"
                           "�Ժ��ٸ���\n������һ��������ʱ��ն�����ǵĹ��ȣ���\n\n" NOR);

}

string look_gate()
{
    	return YEL "һ���������ߵ����ɼľ��ͭ���š�\n" NOR;
}
