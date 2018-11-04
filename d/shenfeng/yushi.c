#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���߽������ǰͻȻ������ֻ��һ�������������ʮ��
�ߴ��ıڷ��������������������֮������һ�����ң�������
�꽨�������������Ȼ���ߣ��ڷ��ж�׼λ�ÿ�����ɡ�ʯ��
������(bed)������(table)�����Σ�����̵����Ǿ��£���
��б����һ�ߺ��ǡ�ʯ��һ����һ��һС�����ߺ��ǡ�
LONG);
        set("objects", ([ 
                __DIR__"obj/skeleton" : 2,
                __DIR__"obj/skeleton2" : 1,
	]));

    	set("exits", ([ 
       		"east" : __DIR__"diantang",

    	]));

    	set("item_desc", ([
        	"table" : HIW "\nԲ�������������ʯ�е�̳����ģ����ڵ��ϣ�Բ����"
                          "��̵�\n��һȺ��������ķ����գ����Ƽ�ϸ���̹����Ǿ���"
                          "��Ȼ����\n�յ�ͷ������ȴ��������һ�𣬸����뿪��һ�߶�"
                          "λ�á�\n" NOR, 

        	"bed" : HIW "\n����һ����ʯ��̳����Ĵ���\n" NOR,
	]));
    	create_door("east", WHT "Сʯ��" NOR, "west", DOOR_CLOSED);
    	setup();
}

void init()
{
    	add_action("do_climb","climb");
    	add_action("do_move","move");
}

int do_climb(string arg)
{
    	if (! arg || arg != "bed")
        	return notify_fail("��Ҫ�������\n");

    	if (this_player()->query_temp("marks/��1"))
        	return notify_fail("���Ѿ��������ˡ�\n");

    	message_vision(HIC "ֻ��$N" HIC "һ�����������񴲡�\n" NOR, this_player());
    	this_player()->set_temp("marks/��1", 1);
        return 1;
}

int do_move(string arg)
{
        object me;
        object room;
        me = this_player();

    	if (! me->query_temp("marks/��1"))
	{
        	write("ʲô��\n");
        	return 1;
    	}

        if (! arg || arg != "table")
	{
        	write("��Ҫ�ƶ�ʲô��\n");
        	return 1;
    	}

    	if (! (room = find_object(__DIR__"yongdao5")))
        	room = load_object(__DIR__"yongdao5");

    	this_player()->delete_temp("marks/��1");

    	if (! query("exits/enter"))
	{
            	set("exits/enter", __DIR__"yongdao5");
            	message_vision(HIW "\n$N" HIW "��Բ�����ػ���������ʹ�����������յ�ͷ"
                               "����������һ���񴲵�ʱ¶��һ�����ڡ�\n\n" NOR, me);
            	room->set("exits/out", __FILE__);
            	return 1;
    	}
        write("��Ҫ�ƶ�ʲô��\n");

        return 1;
}
