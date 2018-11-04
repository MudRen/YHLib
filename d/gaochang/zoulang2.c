inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǵ������ȡ�����һ��֧������ĸ�ǽ�ϣ���һ����
�뱱�ߵ��õ��ݶ�����������������������Ҳ�ò�������˸�
�ַ����ͼ�Σ�ÿ�����ƺ�������˵һ���渶��˵Ĺ��¡�
LONG);

        set("exits", ([
                "southeast" : __DIR__"zoulange",
                "southwest" : __DIR__"zoulangw",
                "north" : __DIR__"mishi",
        ]));
        set("objects", ([
                __DIR__"npc/waer" : 1,
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        int i;
        if (dir == "north")
	{
                i = (int)me->query_temp("long_road");
                i = i + 1;
                if (i == 4)
		{
                	me->delete_temp("long_road");
                	return 1;
                } else
		{
                        me->set_temp("long_road", i);
                	return notify_fail(HIW "\n��ʱ�䣬ֻ��ǰ��һ����ɭɭ��������"
                                           "���������Ѿ������ﰲ\n��������ס��һǧ��"
                                           "�����������������ҡ�ֻҪ��˭�Ҵ󵨹�\n��"
                                           "�������̸������������ʱֻ�����ĵ�ӿ��һ"
                                           "�ɺ��⣬����\nֱ���£����������˽Ų���\n\n" NOR);
                }
        } else
        if (dir == "south")
	{
               	me->delete_temp("long_road");
               	return 1;
        }
	return 1;
}
