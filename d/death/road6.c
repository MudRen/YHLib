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
		"north" : "/d/death/qiao1",
		"south" : "/d/death/road5",
	]));

	set("no_fight", 1);
	set("no_sleep_room", 1);

        setup();
        replace_program(ROOM);
}