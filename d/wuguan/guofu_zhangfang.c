#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�ʷ�");
        set("long", @LONG
����������ڵ�һ���ʷ�������һ���ʷ���������������
�������ʡ������µ�����Χ���ʷ���������������ѻ�������
��Ǯ��������ǽ�Ϲ���һ������(paizi)��
LONG);
        set("no_fight", 1);
        set("exits", ([
                "north" : __DIR__"guofu_shilu-1",
        ]));
        set("objects", ([
                __DIR__"npc/fan" : 1,
        ]) );
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
        setup();
        replace_program(ROOM);
}
