#include <ansi.h>
inherit ROOM;

void enter_furong();

void create()
{
        set("short", "ˮ������");
        set("long", @LONG
��������ɪɪ��һƬ���,ʲôҲ��������Ψ�ж��ڴ���һ
˿������
LONG);

	set("exits",([		
	       "out"   :__DIR__"inhole1",         
	]));	
	     	
        setup();
	
}

void init()
{          
      add_action("do_use","use");	
      add_action("do_zou","zou");	
}


int do_use(string arg)
{ 
    object me;
    me = this_player();

    if (! arg) return 0;
    if (! present("fire", me)) return 0;
    if (arg == "fire" ) 
    {
      write(HIW"\n���ȼ�˻��ۣ����ֶ����ƺ���һ��·����˳����(zou)��ȥ��\n\n"NOR);  
      
      delete("long");
      set("long",@LONG
���Ż���㿴�����й�ʯ��ᾣ�ǰ������һ��·��֪ͨ��
�δ���
LONG);
              
      me->set_temp("marks/��1", 1);

      return 1;
    }
}

int do_zou(string arg)
{
       object me;
       me = this_player();

       if (me->query_temp("marks/��1") ) 
       {
        	tell_object(me, HIR "\n�����Ż���˳��·��ͣ����...\n\n" NOR);
  		
		call_out("enter_furong", 6);      	      
  
        	me->delete_temp("marks/��1");

        	return 1;
       }
       else 
       {
        	write("�������Ķ��ߣ�\n");

        	return 1;
       }
}

void enter_furong()
{
	object me = this_player();

	tell_object(me, HIW "����·������������о����˺ܾã���·Խ��Խ�ͣ���"
			    "��ͨ����һ��ɽ��ġ�\n\n" NOR);				

	me->move(__DIR__"furong");
}
