#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short",HIW "�������á�����" NOR);
	set("long", @LONG
���ǡ��ռ��������������ô���������Կ����ڴ����ľ�ͷ��һ
�Ȳ�֪��ʲô����ľ���Ƴɵش���(men)��
LONG
	);

	set("exits", ([ 
                "down"  : "/d/city/wfoxd",
                "up"    :__DIR__ "thirdroom",
                "enter" :__DIR__ "mingren",
        ]));

        set("item_desc", ([
                "men" : HIY "��������������ľ�ƳɵĴ��ţ�������ȥʮ�ֻ�����\n" NOR,
        ]));

	set ("no_fight",1);
        create_door("enter", "����", "out", DOOR_CLOSED);
     	setup();
        replace_program(ROOM);
}
