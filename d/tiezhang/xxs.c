#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
����һ���ڲ�͸��Ĵ󷿼䡣���еĴ������ú���������ס����¶˿
�����������������������ʮ����ľ���ɵĴ��̣�������������İ��ڼ�
ʱ�õ���Ϣ�����ﾲ���ĵģ��ڰ���ż��������΢��������
LONG    );

        set("exits", ([
                "south" : __DIR__"zoulang-4",
        ]));

        create_door("south", "ľ��", "north", DOOR_CLOSED);

        set("sleep_room", 1);
        set("no_fight", 1);
        set("no_clean_up", 0);

        setup();
}