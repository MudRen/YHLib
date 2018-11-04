#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", "������");
      set("long", @LONG
�����ֽ���һ��ͻ���ɽ���ϣ���Χ��ľɭɭ����Ȫ���ȣ�
�в��޿��������޿�����ɫ�ǳ����ˡ��ɴ����Ϲ�ʮ���̿ɴ�
���϶�����������������
LONG);
      set("outdoors", "emei");
      set("exits", ([
          "southdown" : __DIR__"bailongdong",
          "westup"    : __DIR__"shierpan1",
          "enter"     : __DIR__"wnadian",
      ]));
      setup();
}

int valid_leave(object me, string dir)
{
        int c_skill;

        me = this_player();
        if (dir == "westup")
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
