#include <ansi.h>
inherit ROOM;
 
void create()
{
	set("short", HIR "�����Ŵ����" NOR);
       set("long", HIR @LONG

                    ��     ��     ��     ��

    ������һ����ɭɭ��·�ϣ�ŨŨ��������������ܣ�������Զ��
����ɢȥ�Ƶġ����Ͽ�ȥ����ǿ���Էֱ��һ����¥��ģ����������Լ
���Կ�����յ��������Ũ�����Եø���Ĺ��죬·�����Ը���һ��ľ��
�Ľ������Ŷ��ǰ뿪�ģ����㿴�����������ʲ�ᡣ


LONG NOR );
        set("exits", ([
		"north" : "/d/death/road2",
		"south" : "/d/death/gateway",
		"west" : "/d/death/inn1",
		"east" : "/d/death/inn2",
	]));

	set("no_fight", 1);
	set("no_sleep_room", 1);

        setup();
        replace_program(ROOM);
}