#include <ansi.h>

inherit ROOM;

void create()
{
        set("short",HIW "����������־��չ����" NOR);
	set("long", @LONG
���ǡ���������־���չ����������Կ���һЩ���ϡ�
LONG
	);

	set("exits", ([
                "down" : __DIR__"secondroom",
                "up"   : __DIR__"fourroom",
        ]));

        set("item_desc", ([
                "tenet" : HIW "�ṩ����Ļ�������ҽ�����\n" NOR,
                "item"  : HIW "1.�������ܡ�2.�����ϵ��3.������4.Ϊ����֯�������\n" NOR,
        ]));

        set("no_fight",1);
        setup();
        replace_program(ROOM);
}
