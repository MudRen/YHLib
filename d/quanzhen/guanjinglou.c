#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�۾�¥");
        set("long", @LONG
������һ�������С¥���ǽ�����ׯ԰��Ե�����Ǹ�ƾ��
���羰�ġ������῿�������ϣ������֨֨���졣�����Ѿ���
��û������������������￴�羰�ˡ�����(window)�ϵĴ�ֽ
�Ѿ����˲��٣���һ���������졣
LONG);
        set("outdoors", "quanzhen");
        set("exits", ([
                "north" : __DIR__"houhuayuan",
        ]));
        set("no_clean_up", 0);
        set("item_desc", ([
                "window" : HIY "\n�����ǻ�ɳ���죬��Զ������ʲô"
                           "�����������\n" NOR,
        ]));

        setup();
        replace_program(ROOM);
}
