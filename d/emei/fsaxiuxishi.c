#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
���Ǹ����ֽӴ�����Ů���ǵ���Ϣ�ң�����Ů���ӻ�ɽ֮
ǰͨ���ڴ˽���һ�ޣ��ñ���������ɽ�����ڰ���һ��������
ǽ���м���ľ����
LONG);
        set("exits", ([
                "south" : __DIR__"fsazhaitang",
        ]));
        create_door("south", "��", "north", DOOR_CLOSED);
        set("sleep_room", 1);
        set("no_fight", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
