#include <ansi.h>
inherit ROOM;
 
void create()
{
	set("short", HIR "�����Ŵ����" NOR);
       set("long", HIR @LONG

                    ��     ��     ��     ��

    ������һ����ɭɭ��·�ϣ�ŨŨ��������������ܣ�������Զ��
����ɢȥ�Ƶģ�����·ǰ��ֻ�������ǵļ�յ��������


LONG NOR );
        set("exits", ([
		"north" : "/d/death/road6",
		"south" : "/d/death/road4",
	]));

	set("no_fight", 1);
	set("no_sleep_room", 1);

        setup();
}

int valid_leave(object me, string dir)
{
        int i;
        if (dir == "north") {
                i = (int)me->query_temp("long_road");
                i = i + 1;
                if (i == 35) {
                me->delete_temp("long_road");
                return 1;
                }
                else {
                        me->set_temp("long_road",i);
                        return notify_fail( HIB "\n���������������������ܾ�ɫ��Ȼ��û�б䡭��\n" NOR);
                }
        }
        else {
        if (dir == "south") {
                me->delete_temp("long_road");
                return 1;
                }
        return 1;
        }
}

