#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�����ϰ�");
        set("long", @LONG
��첽�����˳����ϰ���ֻ�����ﲨ�ι��������Ͻ�ˮ��
����ȥ����������һ�鱮(bei)��ǰ�治Զ��������ľ�š�
LONG);
        set("outdoors", "kunming");
        set("exits", ([
                "south" : __DIR__"road7", 
                "north"  :__DIR__"qiao3",
        ]));
        set("item_desc", ([
                "bei" : WHT "\n\n\n            ��������������������������������\n"
                        "            ��                            ��\n"
                        "            ��" NOR + HIW "     ͨ      ��      ��" NOR +
                        WHT "     ��\n"
                        "            ��                            ��\n"
                        "            ��������������������������������\n\n\n" NOR,
        ]));
        setup();
       
        replace_program(ROOM);
}
