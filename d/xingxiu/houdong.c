#include <ansi.h>

inherit ROOM;

#define MUDING "/clone/misc/swmuding"

string look_desk();
string look_pet();

void create()
{
        set("short", "���º�");
        set("long", @LONG
���������������¶��󶴣�����������ʱ���������չ�
������ֻ�����ڵƻ�ͨ�����ƺ������¶�������ࡣ��ǰ��
��һ�����µ�ʯ����desk����ʯ���ϰ��Ÿ�ʽˮ�����������
���ɵ�������Т�����ɵġ�
LONG);
        set("exits", ([
             "south"      : __DIR__"riyuedong",
             "southwest"  : __DIR__"riyuedong1",
        ]));

        set("item_desc", ([
                "desk" :  (: look_desk :),
                "pet"  :  (: look_pet :),
        ]));
               
        setup();

}

string look_desk()
{
       object me = this_player();
       object ob;

       ob = find_object(MUDING);
       if (! ob) ob = load_object(MUDING);       

       if (me->query_temp("move"))
       {
              if (! environment(ob))
                     write(HIC "�������ʯ�������ƶ���������¶��һ��С����ֻ�����з���һ"
                           "��ľ��(mu ding)ģ����������\n����ͼ�뽫����(pick)������\n" NOR);
              else 
                     write(HIW "�������ʯ�������ƶ���������¶��һ��С����ֻ�����пտ���Ҳ��\n" NOR);
       }

       if (me->query_skill("poison", 1) < 160)
              return NOR + WHT "����һ�źܾ��µ�ʯ����ʯ���ϵ���Ÿ������Ƕ��pet��ģ����"
                     "ͼ����������������\n��ʯ����ɢ����������ٸо�ͷ��Ŀѣ������֮����\n" NOR;

       return NOR + WHT "����һ�źܾ��µ�ʯ����ʯ���ϵ���Ÿ������Ƕ��pet��ģ����"
              "ͼ����������������\n��ʯ����ɢ��������������һ���������ã��������Ͼ�Ϳ�о綾����\n" NOR;
}

string look_pet()
{
       object me = this_player();

       if (me->query("family/family_name") != "������" ||
           me->query_skill("xingxiu-qishu", 1) < 160)
               return NOR + YEL "���������򼣬֩�룬Ы�ӣ��ߣ�������ֶ��\n" NOR;

       return NOR + WHT "�������" HIY "�����" NOR + WHT "��" NOR + BLU "�ڹѸ�" NOR + WHT
              "��"HIR "��Ы��" NOR + WHT "��" HIW "ǧ������" NOR + WHT "��" HIY "��" HIM 
              "��" NOR + GRN "��� " NOR + WHT"��������һ�������ѵ��������ʥ�綾����\n" NOR;
}

void init()
{
       add_action("do_move", "move");
       add_action("do_pick", "pick");              
}

int do_move(string arg)
{
       object me = this_player();
       object ob;

       if (! arg || arg != "desk")
             return notify_fail("�����ƶ�ʲô��\n");

       if (me->query_temp("move"))
             return notify_fail("���Ѿ���ʯ���ƿ��ˣ�\n");
       
       ob = me->query_temp("armor/hands");

       if (!ob || ob->query("id") != "jinsi shoutao")
       {
             me->delete_temp("move");

             message_sort(HIC "\n$N" HIC "��ͼ��ʯ���ƿ�������$P�ָ�����ʯ����ȴ����һ���ҽУ�$N" HIC
                            "���ڵ��ϣ�����Ҳû��������һ���غ��ˣ�\n", me);

             me->die();

             return 1;
             
       }

       me->set_temp("move", 1);
       message_vision(HIG "$N" HIG "����ؽ�ʯ���ƿ���\n" NOR, me);
       
       return 1;
}

int do_pick(string arg)
{
      object ob, me;
      object hand;

      me = this_player();

      if (! arg || arg != "mu ding from desk" )
            return notify_fail("��Ҫ��ʲô��\n");

      if (! me->query_temp("move"))
            return notify_fail("��Ҫ��ʲô��������ûʲô���õģ�\n");

      ob = find_object(MUDING);
      if (! ob) ob = load_object(MUDING); 

      if (environment(ob))
            return notify_fail("��ľ�����Ѿ����������ˣ������������ˣ�\n");

      hand = me->query_temp("armor/hands");

      if (! hand || hand->query("id") != "jinsi shoutao")
      {
             me->delete_temp("move");
       
             message_sort(HIM "\n$N" HIM "�������ʯ����ͼ��ȡ��ľ����������ͻȻһֻ��Ы���˳���һ��"
                         "ҧ��$N" HIM "�����ϣ�$N" HIM "�ֽ�һ������ʱ������\n" NOR, me);

             me->die();

             return 1;
      }
  
      message_sort(HIM "\n$N" HIM "�������ʯ����ͼ��ȡ��ľ������ͻȻһֻ��Ы���˳���һ��"
                   "ҧ��$N" HIM "��" + hand->name() + HIM "�ϣ�����$N" HIM "ȴ˿�����˵ؽ�"
                   "��ľ����ȡ�˳�����\n" NOR, me);

      ob->move(me);
      me->delete_temp("move");
   
      return 1;
}

