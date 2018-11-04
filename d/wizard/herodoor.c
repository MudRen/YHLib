
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIW "Ӣ��ʥ��" NOR);
	set("long", HIY "\n\n"
"       ��   һ   ��   ��   ��   ��   ��   ��   ��\n"
"       ��   ��   ��   ��   ��   ɽ   ��   ��   ��\n"
"       ��   ��   ��   ��   Ϧ   ��   ��   ��   ��\n"
"       ��   ��   ��   ��   ��   ��   ��   ��   ��\n"
"       ��   ϲ   ��   ��   ��   ��   ת   Ӣ   ��\n"
"       ��   ��   ��   �             ͷ   ��   ��\n"
"       ��   ��        ��             ��        ˮ\n"
"       Ц                                        \n"
"       ̸                                        \n"
"       ��                                        \n\n" NOR

       );                

	set("exits", ([
             "enter" :  __DIR__"hall",
             "up"    :  "/d/city/wumiao",
                      "west"      :   __DIR__"wenxuan",
        ]));

	set("no_fight", 1);

	setup();
       replace_program(ROOM);
}