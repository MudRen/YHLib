#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������������µ������������õĴ������ڣ������ڷǳ�
�Ŀ��������������µ���վ�����У���Ŀ��ȥ��һ����Ȼ��
������������һ���ľ��(bian)��
LONG);
        set("exits", ([
            	"south" : __DIR__"chlang1",
            	"north" : __DIR__"qinggate",
        ]));
        set("item_desc", ([
                "bian" : WHT "\n\n        ����������������������������\n"
                              "        ��                        ��\n"
                              "        ��   " HIG "�������  ��������" NOR + WHT "   ��\n"
                              "        ��                        ��\n"
                              "        ��   " HIG "ǧ������  һͳ����" NOR + WHT "   ��\n"
                              "        ��                        ��\n"
                              "        ����������������������������\n\n\n" NOR,
        ]) );
        set("objects",([
                __DIR__"npc/dizi5" : 4,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
