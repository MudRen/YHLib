#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������ݳ���һ����������ƽ���Ƶĵ��̣�һ����߸�
�Ĺ�̨���������ǰ����̨�ϰ���һ������ (paizi)����̨��
�������ϰ壬һ˫�������������´������㡣
LONG);
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
        set("item_desc", ([
                "paizi" : WHT "\n\n        ����������������������\n"
                              "        ��                  ��\n"
                              "        ��     ��ƽ����     ��\n"
                              "        ��                  ��\n"
                              "        ��  " NOR + HIW "����" NOR + WHT "��   " NOR + HIY "sell" NOR + WHT "   ��\n"
                              "        ��                  ��\n"
                              "        ��  " NOR + HIW "���" NOR + WHT "��   " NOR + HIY "buy" NOR + WHT "    ��\n"
                              "        ��                  ��\n"
                              "        ��  " NOR + HIW "����" NOR + WHT "��   " NOR + HIY "value" NOR + WHT "  ��\n"
                              "        ��                  ��\n"
                              "        ��                  ��\n"
                              "        ����������������������\n\n\n" NOR,
        ]));
	set("objects", ([
		__DIR__"npc/tang" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"nandajie1",
	]));

	setup();
	replace_program(ROOM);
}
