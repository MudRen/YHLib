#include <room.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����������������ײ㡣��(window)����Ũױ��Ĩ�����Ӻ�����
������˽ǣ���ש���أ��������ܼ�ճ����Щ��������
LONG);
        set("exits", ([
            "out"   : __DIR__"liuheta",
            "up"    : __DIR__"liuhe2",
        ]));
        set("item_desc", ([
            "window": "�Ӵ�������ȥ��Ǯ����ȥ������ũ���У���һũ�����ɳ����š�\n",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
