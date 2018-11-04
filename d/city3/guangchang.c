inherit ROOM;

void create()
{
	set("short", "�㳡");
	set("long", @LONG
�����ǳɶ��ᶽ��ǰ�㳡���ÿտ��ĵط���ֻ��ϡϡ����
����û����ɵ����ˡ���������ᶽ���ˣ��ϱ����ᶽ�֡���
����Χ����һȦ���������������԰ѵ���ɹ�ù���ð�̡�
LONG );
        set("outdoors", "chengdu");
	set("exits", ([
	    	"east"  : __DIR__"shuduroad1",
	    	"west"  : __DIR__"shuduroad2",
	    	"south" : __DIR__"tiduroad",
	    	"north" : __DIR__"tidugate",
	]));

	set("objects", ([
                  "/d/city/npc/wujiang" : 2,
	]));
	setup();
}

int init()
{
       add_action("do_get", "get");
       add_action("do_eat", "eat");
       add_action("do_drink", "drink");
}

int do_drink()
{
       write("��������ȣ�\n");
       return 1;
}

int do_eat()
{
       write("Ҫ�Ե��𴦳ԣ�\n");
       return 1;
}

int do_get(string arg)
{
       object me = this_player();
      
       if (!arg)return 0;

       if (arg == "all")
       {
               write("��Ҫ̰�ģ�����һ��һ���ؼ�ɣ�\n");
               return 1;
       }
      
       if (me->is_busy() || me->is_fighting())
       {
               write("�㻹��æ������˵�ɣ�\n");
               return 1;
       }
       
       if (me->query_temp("pick_gift"))
       {
               write("��ռ���ˣ��ȵ��ټ�ɣ�\n");
               return 1;
       }
   
       me->set_temp("pick_gift", 1);
       call_out("clear_flag", 2, me);
       return 0;
}

void clear_flag(object me)
{
       if (objectp(me) && me->query_temp("pick_gift"))
                me->delete_temp("pick_gift");

       return;
}
