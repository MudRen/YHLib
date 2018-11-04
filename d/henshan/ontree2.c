#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�㼫ĿԶ�������ܾ��������ͱڡ�һ������(teng)������
ǰ���¡���Ȼ���㿴��ǰ���ͱ����ƺ���һ��ɽ��(hole)����
�Ǿ�����Զȴ����ôҲ����ȥ��
LONG);
        set("exits", ([ 
               "down" : __DIR__"ontree",
           ]));

	set("item_desc", ([
               "hole"    : HIC "\n̫Զ�ˣ����ò�̫���������������취��ȥ��\n"	NOR,
           
	       "teng"    : YEL"\n��Щ���ٿ������ܽ�ʵ�������������Ÿ���������ȥ��\n" NOR,
	]));


	setup();
}

void init()
{
       add_action("do_la", "la");
       add_action("do_tiao", "tiao");
      
}

int do_la(string arg)
{
	object me;

	me = this_player();
	
	if (! arg || arg != "teng")
		return notify_fail("�����ʲô��\n");

        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ������˵��\n");

        if (me->query_temp("la_teng"))
                return notify_fail("���Ѿ������˰���\n");

        message_vision(NOR + YEL "$N" NOR + YEL "˫�ֽ�����ס���٣���������"
                       "��ʵ��\n" NOR, me);

        me->set_temp("la_teng", 1);
                  
	return 1; 
	
}

int do_tiao(string arg)
{
	object me;

	me = this_player();
	
	if (! arg || arg != "hole")
		return notify_fail("�����ʲô��\n");

        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ������˵��\n");

        if (! me->query_temp("la_teng"))
                return notify_fail("̫Զ�ˣ���������������ȥ��\n");

        if (random(6) != 1)
        { 
              message_sort(HIC "\n$N" HIC "˫�ֽ�����ס���٣��ڿն�����ɽ����ȥ���������١�ž~����һ��"
                           "�ڰ�նϵ���$N " HIC "���ص�ˤ����ȥ����\n\n" NOR, me);
              me->move(__DIR__"xuanyadi");
              me->delete_temp("la_teng");
              me->unconcious();
              return 1;
       }

       message_sort(HIC "\n$N" HIC "˫�ֽ�����ס���٣��ڿն�����ɽ����ȥ�������ڿ��л���һ������Ļ��ߡ�"
                    "$N" HIC "ֻ�����߷������������ܿ�$N" HIC "����������˶��ڣ���ͷ���������ڿ���ҡ��"
                    "�ţ�\n\n" NOR, me);

      me->delete_temp("la_teng");
      me->move(__DIR__"outzhushendong");     
          
      return 1; 
	
}