#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ף�ڷ�");
        set("long",
"ף�ڷ�֮��Ϊ��ɽ���ľ�֮�ס��ڴ˸��Ⱥ�壬�����۵ס�\n"
"�����潭���ϼ����룬���ͥ������ѩɽ���Ƴ��Ÿ�����ʫ"
"\n���С�" HIW "ף������𣬷��εͰ�" NOR "��������ʫ�˺�"
"�����ԡ�" HIW "ף��\n���ɰε�����������������" NOR "��"
"������ߡ�\n");
        set("exits", ([
                "eastdown"   : __DIR__"shanlu004",
        ]));

        set("objects", ([
                CLASS_D("henshan") + "/mo" : 1,
        ]));    

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

