
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIC "�������" NOR);
	set("long", @LONG
������Ӣ��ʥ��ķ���������й�Ӣ��ʥ����κ�����
�������������˽⵽��
LONG);                

	set("exits", ([
             "out"   :  __DIR__"herodoor",
             "west"  :  __DIR__"noname_room",
             "east"  :  __DIR__"guest_room",
             "north" :  "/u/rcwiz/mail_center/mailcenter"
        ]));

	set("no_fight", 1);

	setup();
}