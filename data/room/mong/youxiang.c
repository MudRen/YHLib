
#include <room.h>

inherit PRIVATE_ROOM;

void create()
{
	set("short", "���᷿");
	set ("long", @LONG
����Ǭ���ӵ����᷿���ǿ��˾�ס�ĵط�����Ȼ�����ݻ���ȴҲ
���õ÷ǳ����ʡ�һ�Ŵ�����ɾ���û�ж������ƣ�����������ʵ��
ʹ���ڹ���ǡ���ô��� 
LONG );

	set("exits", ([
                "east" : __DIR__"zhongting",
	]));

        set("sleep_room", 1);
        set("no_fight", 1);

        create_door("east", "ľ��", "west", DOOR_CLOSED);

        setup();

        set("room_owner", "����");
        set("room_name", "Ǭ����");
        set("room_id", "qiankun");
        set("room_owner_id", "mong");
        set("room_position", "��ʯ���");
}
