#include <ansi.h>
inherit ROOM;
 
int do_stuff(object ob);
 
void create()
{
        set("short", HIB "��С�꡿" NOR);
        set("long", HIB @LONG

                      С                ��  

    ��һ�����ͷ��������쳣����ů��ǽ�Ǳ�¯��΢���Ļ�⽫���Ӱ
��Ͷ���ڶ����ǽ�ϡ�������ӰΧ��¯�Բ�֪������Щʲ�ᡣ�����м�
��ľ�����Σ�ǽ�Ϲ��˼����ֻ���һ�п����ǳ�������������㼸����
���Լ����ںδ���


LONG NOR );
        set("exits", ([
                 "east" : "/d/death/road1",
        ]));
 
	set("objects", ([
		__DIR__"npc/ghost": 1,
	]) );

	 set("no_fight", 1);
	 set("no_sleep_room", 1);

        setup();
        replace_program(ROOM);
}

