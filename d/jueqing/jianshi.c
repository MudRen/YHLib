#include <ansi.h>

#define JUNZI   "/clone/lonely/junzijian"
#define SHUNV   "/clone/lonely/shunvjian"

inherit ROOM;

string look_hua();

void create()
{
        set("short", "����");
        set("long", @LONG
ֻ�����еı��ϡ����ϡ����ϡ������˸�����У�ʽ����
�࣬ʮ֮�˾Ŷ��ǹŽ��������߳ߣ���̽����磬�е�����
�����еĺ�����ˣ�ֱ�������۹����ҡ���Զ����ǽ���Ϲ���
��һ���Ż�(hua)��
LONG);
        set("item_desc", ([
               "hua" : ( : look_hua :),
        ]));

        set("exits", ([
               "south" : __DIR__"houtang",
        ]));

        set("no_clean_up", 0);
        setup();
}

string look_hua()
{
      object ob, junzi, shunv;
      string msg;

      if (! ob = find_object(__DIR__"jianshi"))
              ob = load_object(__DIR__"jianshi");

      if (! ob->query_temp("marks/��"))
              return HIW "�Ż��Ѿ��ƾɲ���������һ����Ů����һ���޷�֮����\n" NOR;

      msg = HIY "���ѱ���˺�ơ�" NOR;

      junzi = find_object(JUNZI);
      shunv = find_object(SHUNV);


      if (! junzi) junzi = load_object(JUNZI);
      if (! shunv) shunv = load_object(SHUNV);

      if (! environment(junzi) && ! environment(shunv))    
      { 
              msg += HIY "���������ж����޷�֮��������ȥ����һ�ԡ�\n" NOR;
              return msg;          
      } else
      if (! environment(junzi) || ! environment(shunv))
      {
              msg += HIY "����������һ�����ڰ߲���������˵ı�����\n" NOR;
              return msg;
      }

      msg += HIY "����տ���Ҳ��ʲô��û�С�\n" NOR;
      return msg;
}

void init()
{       
        add_action("do_pull", ({ "pull" }));
        add_action("do_pick", ({ "pick" }));
}

int do_pull(string arg)
{
        object me = this_player();
        object ob;

        if (! arg || arg != "hua")
                return notify_fail("��Ҫ��ʲô��\n");

        if (! ob = find_object(__DIR__"jianshi"))
                ob = load_object(__DIR__"jianshi");

        if(ob->query_temp("marks/��"))
        {
                write("���Ѿ��������ˡ�\n");
                return 1;
        }

        message_vision(HIG "ֻ���������ꡱһ����$N " HIG "��ǽ�ϵĻ�"
                       "�����ˡ�\n" NOR, me);
        ob->set_temp("marks/��", 1);

        return 1;
}

int do_pick(string arg)
{
        object ob,me;
        object junzi,shunv;

        me = this_player();

        if (! ob = find_object(__DIR__"jianshi"))
                ob = load_object(__DIR__"jianshi");

        if (! arg || (arg != "junzi jian" && arg != "shunv jian" ))
                return notify_fail("��Ҫ��ʲô��\n");
        
        if (ob->query_temp("marks/��") && ob->query_temp("marks/Ů")
            || ! ob->query_temp("marks/��"))
                return notify_fail("��Ҫ��ʲô��\n");

        junzi = find_object(JUNZI);
        shunv = find_object(SHUNV);

        if (! junzi) junzi = load_object(JUNZI);
        if (! shunv) shunv = load_object(SHUNV);

        if (arg == "junzi jian")
        {
                 if (! environment(junzi))
                 {
                         junzi->move(me, 1);
                         message_vision(HIC "$N" HIC "��ǽ�ϵġ����ӽ���"
                                        "ȡ��������\n" NOR, me);
                         return 1;
                 } else
                         return notify_fail(NOR + YEL "���ӽ��ѱ����ߡ�\n" NOR);
        }   

        if (! environment(shunv))
        {
                shunv->move(me, 1);
                message_vision(HIC "$N" HIC "��ǽ�ϵġ���Ů����"
                               "ȡ��������\n" NOR, me);
                return 1;
        } else
                return notify_fail(NOR + YEL "��Ů���ѱ����ߡ�\n" NOR);        

        return 1;
}
