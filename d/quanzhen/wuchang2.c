#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�䳡");
        set("long", @LONG
������ȫ��̵����䳡�����µ���ש�����̵���������ȴ
��֪����˭�ȳ��˼�ʮ�����СС�İ��ӡ����ĳ����������
�����µ��е��������Ʒ��������쳤�վã����¾Ͳȳ��˰��ӡ�
LONG);
        set("outdoors", "quanzhen");
        set("exits", ([
                "north" : __DIR__"wuchang1",
                "east"  : __DIR__"xiuxishi",
                "south" : __DIR__"wuchang3",
                "southeast" : __DIR__"shantang",
        ]));

        set("for_family", "ȫ���");

        setup();
        replace_program(ROOM);
}
