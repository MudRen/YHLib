#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", "ʮ����");
      set("long", @LONG
����ʯ�׶��۶��䣬�ųơ�ʮ���̡������·���и�����
�أ�������������л���(clap)���ɴ����Ͽɴﻪ�϶�������
�������֡�
LONG);
      set("outdoors", "emei");
      set("exits", ([
          "eastdown"  : __DIR__"shierpan2",
          "southwest" : __DIR__"shierpan4",
      ]));
      set("no_clean_up", 0);
      setup();
}

void init()
{
      add_action("do_clap", "clap");
}

int do_clap()
{
      message_vision(HIC "\n���ں�Ȼ���ܴ���һ��������Ⱥ�ܴε���"
                     "�ϣ��������һ�ܴ�\n����Ⱥ�ܱ��Ȼ��ֹ����"
                     "������Ϊ�ˡ�\n", this_player());
      return 1;
}

int valid_leave(object me, string dir)
{
        int c_skill;

        me = this_player();
        if (dir == "southwest")
        {
                c_skill = me->query_skill("dodge", 1);
                if (me->query("qi") > 40)
                {
                        me->receive_damage("qi", 20 + random(20));

                        if (me->can_improve_skill("dodge") && c_skill < 100)
                                me->improve_skill("dodge", 1 + c_skill / 15);

                        tell_object(me, HIC "������ʮ���̣���Щ���ˡ�\n" NOR);
                } else
                {
                        me->set("qi", 0);
                        tell_object(me, HIR "��̫���ˣ���Ҳ�߲����ˡ�\n" NOR);
                        return -1;
                }
      }
      return 1;
}
