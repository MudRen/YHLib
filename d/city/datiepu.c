#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ�Ҽ�ª�Ĵ����̣����İ���һ����¯��¯�������
�յ�һƬͨ�죬��һ�߽�ȥ�͸е�������ȡ�ǽ�Ƕ���������
����δ�깤�Ĳ˵���������������ذ�ס����׵��һλ����
��ͷ�󺹻�����������ר����־���ڴ����������̶��׵�ǽ��
��������һ������(paizi)��
LONG);
        set("item_desc", ([
                "paizi" : WHT "\n\n        ������������������������\n"
                              "        ��                    ��\n"
                              "        ��      " NOR + HIW "����ά��" NOR + WHT "      ��\n"
                              "        ��                    ��\n"
                              "        ��  " NOR + HIY "repair  <����id>" NOR + WHT "  ��\n"
                              "        ��                    ��\n"
                              "        ��                    ��\n"
                              "        ������������������������\n\n\n" NOR,
        ]));
	set("exits", ([
		"north" : __DIR__"dongdajie2",
	]));
        set("objects", ([
		__DIR__"npc/smith": 1,
	]));
	setup();
	replace_program(ROOM);
}

