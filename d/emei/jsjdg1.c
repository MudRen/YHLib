#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", "��ʮ�ŵ���");
      set("long", @LONG
���Ǳ��������ġ���ʮ�ŵ��ա�����·����������ǧ�۰�
�ء���˵��ȥ���и�������ķ�ɮ���ˣ���һ������·������
�������������ǵ�֪�˴��о�����û�󣬱���Ҳ���˸�������
�Ĳ�ľ�����ԡ����ӡ���֮��������ǧ���֣�������϶���
LONG);
      set("outdoors", "emei");
      set("exits", ([
          "westup"   : __DIR__"jsjdg2",
          "eastdown" : __DIR__"qianfoan",
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

                        tell_object(me, HIC "�����Ͼ�ʮ�ŵ��գ���Щ���ˡ�\n" NOR);
                } else
                {
                        me->set("qi", 0);
                        tell_object(me, HIR "��̫���ˣ���Ҳ�߲����ˡ�\n" NOR);
                        return -1;
                }
      }
      return 1;
}
