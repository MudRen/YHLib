#include <room.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�������������ĵ�ʮ�㡣��(window)����Ũױ��Ĩ�����Ӻ�����
������˽ǣ���ש���أ��������ܼ�ճ����Щ��������
LONG);
        set("exits", ([
            "down"  : __DIR__"liuhe9",
            "up"    : __DIR__"liuheb",
        ]));
        set("item_desc", ([
            "window": "�Ӵ�������ȥ��Ǯ����ȥ������ũ���У���һũ�����ɳ����š�\n",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
