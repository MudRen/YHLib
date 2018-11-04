#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
�������޺���������ʯͷ�̳ɵ�һ��С������Χ��������
���������һ��˵����������ζ��·���и�ʯ����
LONG);
        set("exits", ([ 
            	"east" : __DIR__"xxh4",
            	"enter" : __DIR__"xiaoyao",
        ]));

        set("objects", ([ 
            	__DIR__"npc/caihua" : 1,
        ]));

        set("outdoors", "xingxiu");

        setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if (dir == "enter")
	{
	        if (present("caihua zi", environment(me)))
		{
                        if (! myfam || myfam["family_name"] != "������") 
                	        return notify_fail(CYN "�ɻ��ӵ�ס���㣺�ҵ�С椿ɲ���"
                                                   "������а�ɵ���׼���ģ�\n" NOR);

                        if  (me->query("gender") == "����") 
                                return notify_fail(CYN "�ɻ��ӵ�ס���㣬һ����Ц������"
                                                   "С��廹����椣�����Ц�ˡ�\n" NOR);

                        if (! (int)this_player()->query_temp("marks/��"))
                                return notify_fail(CYN "�ɻ��ӵ�ס���㣺ι�����ܸ���˼"
                                                   "��˼�ɣ�\n" NOR);
                }
	        return 1;
        }
        return ::valid_leave(me, dir);
}
