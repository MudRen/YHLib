#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", "ǧ����");
      set("long", @LONG
�˴��Ǻ鴻ƺǧ���֡�ɽ��Сƺ�ӣ�������͵��ϣ��廷
�뻤�����������ᰣ�Ϫ���ᶣ��ƺ�Ϲ�ľ���裬ͤͤ���ɽ
����͸������Ʈ�Σ���Ϊ�ľ��������˴�������������������
�������ɣ���ɽ��������Ϊ������ν��ɽ�б����꣬�մ�ʪ��
�¡����������Ϊ��۵ġ��鴻���꡹���˴��������ģ�����
���죬����������;�����ǡ���ʮ�ŵ��ա������¾�������
ջ����������
LONG);
      set("outdoors", "emei");
      set("exits", ([
          "westup" : __DIR__"jsjdg1",
          "east"   : __DIR__"heilong2",
          "enter"  : __DIR__"qfadadian",
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
