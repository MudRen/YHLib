#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ˮ������");
        set("long", @LONG
��������ɪɪ��һƬ���,ʲôҲ��������Ψ�ж�����һ˿
������
LONG);

	set("exits",([		
	       "out"   :__DIR__"inhole1",	      
	]));	
	     	
       setup();
}

void init()
{
        add_action("do_use","use");
}

int do_use(string arg)
{
    object me,ob;
    me = this_player();

    if (! ob = find_object(__DIR__"inhole2"))
		ob=load_object(__DIR__"inhole2");	

    if (! arg || arg != "fire" ) return 0;
    if (! present("fire", me)) return 0;
   
        write(HIG"\n���ȼ�˻��ۣ����������г��ڡ�\n\n"); 
        me->set_temp("marks/��1",1);

        delete("long");
        set("long",@LONG
���Ż���㷢��������һЩ���ڣ�����֪��ͨ���δ���
LONG);  
            
        set("exits/west"  ,__DIR__"zigai1");
        set("exits/north" ,__DIR__"zigai2");
	         	
        return 1;
}

void reset()

{
         ::reset();

         delete("exits/west");
         delete("exits/north");

}
