#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","Ӣ�۵䵱");
	set("long",@LONG
������һ�Ÿ߸ߵĹ�̨����̨�������ŵ��̵ĳ�����
�����Ƿ���ү������ʮ��������û�����ֹ��£�����Ҳ�ͺܷ�
�ġ���̨�Ϲ���һ��ľ����(paizi)��
LONG);
        set("no_fight", 1);
        set("no_steal", 1);
        set("no_beg", 1);
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
	        __DIR__"npc/chaofeng": 1,
	]));

	set("exits", ([
	        "north"  : __DIR__"street5",
	]));
	setup();
	replace_program(ROOM);
}
