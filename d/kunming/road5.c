#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
��첽�����˳���������ֻ�����ﲨ�ι��������Ͻ�ˮ��
����ȥ����������һ�鱮(bei)��ǰ�治Զ��������ľ�š�
LONG);
        set("outdoors", "kunming");
        set("exits", ([
                "south" : __DIR__"qiao", 
                "north" :__DIR__"road4",                
        ]));
        set("item_desc", ([
                "bei" : WHT "\n\n\n            ��������������������������������\n"
                        "            ��                            ��\n"
                        "            ��" NOR + HIW "     ͨ      ��      ��" NOR +
                        WHT "     ��\n"
                        "            ��                            ��\n"
                        "            ��������������������������������\n\n\n" NOR,
        ]));
        set("objects", ([
                "/d/beijing/npc/tiaofu" : 2,
        ]));
        setup();
        replace_program(ROOM);
}
