//Room: ssyb.c �����±�

inherit ROOM;

#include <ansi.h>

void create()
{
      set("short","�����±�");
      set("long", @LONG
�������ε��±ڡ�̧ͷ������΢����⡣���泱ʪ���ѷ���΢��ˮ��
�������������ǵĳ�ˮ���Ա߲�Զ����һ����Ĺ(fenmu)�� �򶫾�������
ʱ��ˮ̶��
LONG);
      set("outdoors", "emei");
      set("objects", ([
          __DIR__"npc/frog" : 1 + random(3),
      ]) );

         set("exits",  ([
                 "east" : __DIR__"st0",
         ]));
      set("item_desc", ([
            "fenmu" : NOR + WHT "���������Ĺ�Ѿ�������ܾ��ˣ������ѳ�������̦������һ������"
                      "��Ȼ֮�������\n" NOR,
      ]));
      set("no_clean_up", 0);
      set("no_fight", 1);
      setup();
}

void init()
{
    add_action("do_climb", "climb");
    add_action("do_bai", "bai");
}

int do_climb()
{
    object me;
    me = this_player();
    message("vision", me->name()+"ʹ������ȥ�����˾�ţ����֮����\n", environment(me), ({me}) );
    me->move(__DIR__"gudelin1");
    message("vision", me->name()+"���˾�ţ����֮������������ط���ȴ��֪�������\n", environment(me), ({me}) );

    return 1;
}

int do_bai(string arg)
{
     object book;

                 object me = this_player();
     if (! arg || arg != "fenmu")
            return 0;
     if (me->is_busy() || me->is_fighting())
     {
            write("��æ������˵�ɣ�\n");
            return 1;
     }
     if (me->query("jing") < 130)
     {
            write("�㾫�����㣡\n");
            return 1;
     }
     if (me->query("jing") > 200)me->add("jing", -120);
     else me->set("jing", 1);

     write(HIG "�����в�Ȼ֮����Ȼ���� ����\n" NOR);
     write(HIG "�������Ĺ��Ĩȥ�������̦�����ڵ��Ͽ�������ͷ��\n" NOR);
     me->start_busy(2 + random(2));
     if (this_player()->query_skill("shaolin-jiuyang", 1) < 180
        || this_player()->query_skill("wudang-jiuyang", 1) < 180)
     {
             write(HIG "���Ȼ������̶�׺����ޱȣ����뻹�ǸϿ��뿪Ϊ�á�\n" NOR);
             return 1;      
     }

     if (random(500) != 1)
     {
             write(HIG "��ͷ��ϣ��㻺��վ��������ĬĬ��ע���ŷ�Ĺ������˼����ǧ��\n" NOR);
             return 1;
     }

     write(HIG "��Ȼ�������һ��ӲӲ�Ķ�������ͷ�ϣ��������͵��ڿ���Ĺ ����\n" NOR);
     write(HIG "һ��ľ�г���������ǰ�����æ��ľ�У���ಡ���һ����һö�������зɳ�����\n" NOR);
     if (this_player()->query_skill("dodge", 1) < 220 || 
         this_player()->query_skill("martial-cognize", 1) < 220)
     {
          write(HIG "�����㲻�������������ؿڴ�����\n" NOR);
          this_player()->unconcious();
     }
     write(HIG "�����ڴ򿪺���֮ǰ�����ϵ����ж����а�������������ݲ��ȵض��˹�ȥ��\n" NOR);
     if (! book = find_object("/clone/lonely/book/emeijy-book"))
           book = load_object("/clone/lonely/book/emeijy-book");
     if (environment(book))
     {
          write(HIG "���ͷһ����ȴ���ֺ����ǿյģ�\n" NOR);
          return 1;
     }
     write(HIG "���æ��������Ķ������˳�����\n" NOR);
     book->move(this_player());
     return 1;
                  
}
