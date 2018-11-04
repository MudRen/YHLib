#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ʥ��");
        set("long", @LONG
��ǰ����������ʥ���������ĺ��浹Ӱ������Ͱ��ƣ���
��ˮ�������Ŀ���������̻Ի͵Ĵ����������ɼ�����Զ��
�Ǽ�������Ĵ�ѩɽ��������ߴ������ɽ���ഫɽ��������
��ס��ѩɽ���ڻ���ѩˮ��������С�������Χȴ�Ǳ���Ũ��
���������֣�ʹ�����ǰһƬ���ʣ��Ʋ������ܡ�
LONG );
        set("resource/water", 1);
        set("exits", ([
                "east" :  __FILE__,
                "west" :  __FILE__,
                "south" : __FILE__,
                "north" : __FILE__,
        ]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
        set("outdoors", "xuedao");

        setup();
}

int valid_leave(object me, string dir)
{
        int total_steps;

        if (! userp(me)
           || me->query("family/family_name") == "������"
           || me->query("family/family_name") == "Ѫ����")
        {
                total_steps = 1; 
        } else
        {
                me->receive_damage("jing", 5);
                me->receive_wound("jing", 5);
                message_vision(HIM "\nͻȻ��$N" HIM "������ǰ�ľ�����"
                               "Щ���ң���������ͷ��Ŀѣ��\n\n" NOR, me);

                total_steps = 5;
        }

        if (dir == "east")
                me->add_temp("taohua/steps", 1);

        if (dir == "south")
                me->add_temp("taohua/steps", -1);

        if (me->query_temp("taohua/steps") == total_steps)
        {
                me->move(__DIR__"hubian1");
                me->delete_temp("taohua/steps");
                write(HIC "\n����ɢ���������ǰ��Ȼ����������\n\n" NOR);
                return -1;
        }  

        if (me->query_temp("taohua/steps") == - total_steps)
        {  
                me->move(__DIR__"tulu3");
                me->delete_temp("taohua/steps");
                write(HIC "\n����ɢ���������ǰ��Ȼ����������\n\n" NOR);
                return -1;
        }

        return ::valid_leave(me, dir);
}
