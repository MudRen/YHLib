#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", NOR + RED "��������" NOR);
        set("long", @LONG
������ʯ���ڵ�һ�ð��̸ߵĴ������ϣ������˴�����Ҷ
���ǣ��ܲ�͸�硣
LONG);
        set("exits", ([
              "up"    :  __DIR__"ontree3",
              "down"  :  __DIR__"ontree1",
        ]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

