#include <ansi.h>
inherit ROOM;
 
void create()
{
        set("short", RED "������ͨ����" NOR);
       set("long", RED @LONG

                    ��     ��     ͨ     ��

    һ������˾��������Ľ��ݣ���֪��ͨ���η�����������ף���
����Զû��ֹ��һ�㡣

LONG NOR );
        set("exits", ([
                "up" : __DIR__"lunhuisi",
                "down" : __DIR__"diyin_road2",
        ]));

        set("no_sleep_room", 1);

        setup();
}

int valid_leave(object me, string dir)
{
        int i;
        if (dir == "down")
        {
                i = (int)me->query_temp("long_road");
                i = i + 1;

                if (i == 10)
                {
                        me->delete_temp("long_road");
                        return 1;
                }
           else {
                        me->set_temp("long_road",i);
                        return notify_fail( RED "\n����������������׵Ľ��ݡ���"
                                            "ֻ�������ƺ����������죬��Զ���ﲻ�˾�ͷ"
                                            "һ�㡣\n" NOR);
                }
        }
   else {
                if (dir == "up")
                {
                        me->delete_temp("long_road");
                        return 1;
                }
        return 1;
        }
}
