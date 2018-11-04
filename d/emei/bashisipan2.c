#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ʮ����");
        set("long", @LONG
��ʮ���̣���·���ն��ͣ��ػ����ۣ����˲��ܴ�Ϣ��·
���Ǳ����������ɼ�֣�·��������׵ľ���Ͽ�ȡ��ɴ���
������������µ�ϴ��ء�
LONG);
        set("outdoors", "emei");
        set("exits", ([
                "southup"   : __DIR__"bashisipan3",
                "northeast" : __DIR__"bashisipan1",
                "east"      : __DIR__"lengsl3",
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        int c_skill;

        me = this_player();
        if (dir == "southup")
        {
                c_skill = me->query_skill("dodge", 1);
                if (me->query("qi") > 40)
                {
                        me->receive_damage("qi", 20 + random(20));

                        if (me->can_improve_skill("dodge") && c_skill < 100)
                                me->improve_skill("dodge", 1 + c_skill / 15);

                        tell_object(me, HIC "�����ϰ�ʮ���̣���Щ���ˡ�\n" NOR);
                } else
                {
                        me->set("qi", 0);
                        tell_object(me, HIR "��̫���ˣ���Ҳ�߲����ˡ�\n" NOR);
                        return -1;
                }
      }
      return 1;
}