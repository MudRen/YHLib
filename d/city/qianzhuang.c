#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "Ǯׯ");
	set("long", @LONG
����һ�����ֺŵ�Ǯׯ�����м��������ʷ����ȫ������
���зֵꡣ�����е���Ʊ�����ǳ��ã�ͨ��ȫ�����ڶ����ǽ
�Ϲ��˿�����(paizi)��
LONG);
        set("no_fight", 1);
        set("no_steal", 1);
        set("no_beg",1);
        set("item_desc", ([
                "paizi" : WHT "\n\n        ����������������������\n"
                              "        ��                  ��\n"
                              "        ��     ��ƽ����     ��\n"
                              "        ��                  ��\n"
                              "        ��  " NOR + HIW "��Ǯ" NOR + WHT "�� " NOR + HIY "deposit" NOR + WHT "  ��\n"
                              "        ��                  ��\n"
                              "        ��  " NOR + HIW "ȡǮ" NOR + WHT "�� " NOR + HIY "withdraw" NOR + WHT " ��\n"
                              "        ��                  ��\n"
                              "        ��  " NOR + HIW "�һ�" NOR + WHT "�� " NOR + HIY "convert" NOR + WHT "  ��\n"
                              "        ��                  ��\n"
                              "        ��  " NOR + HIW "����" NOR + WHT "�� " NOR + HIY "check" NOR + WHT "    ��\n"
                              "        ��                  ��\n"
                              "        ��                  ��\n"
                              "        ����������������������\n\n\n" NOR,
        ]));
	set("exits", ([
		"east" : __DIR__"beidajie1",
	]));
	set("objects", ([
		__DIR__"npc/qian" : 1
	]));
	setup();
	replace_program(ROOM);
}

