#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�������");
        set("long", @LONG
�����Ǵ���������������ݵ�����͵��˾�ͷ��ǽ���Ͽ�
�ż�������(window)������������������������ж���
LONG);
        set("exits", ([
                "eastdown" : __DIR__"cundaota3",
        ]));
        set("objects", ([
                __DIR__"npc/zhangjing" : 1,
        ]));

        set("item_desc", ([
                "window": HIW "\n�������Ʈ�����ƺ���һ���־Ϳ���ץסһƬ��\n" NOR,
        ]));

        set("count",1);
        setup();
        replace_program(ROOM);
}
