#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", NOR + GRN "����" NOR);
        set("long", @LONG
�������Ӽ��٣������һƬ���ָ��Ǻ������Ų�������
�֣��ŵ�һ���󵭵����㣬�Ǿ����׾�����
LONG);
        set("outdoors", "jueqing");
        set("exits", ([
               "west"  : __DIR__"zizhuxuan",
        ]));

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
