
#include <room.h>

inherit PRIVATE_ROOM;

void create()
{
	set("short", "����");
	set ("long", @LONG
�����Ǭ��������������Ϣ������ĵط���¥�Ͼ������˵����ң�
���������鷿�� 
LONG );

	set("exits", ([
		"up"   : __DIR__"woshi",
                "west" : __DIR__"shufang",
	]));

        set("no_sleep_room", 1);
        setup();

        set("KEY_DOOR", ([
                "exit" : "east",
                "room" : __DIR__"huayuan",
        ]));
    
        set("room_owner", "����");
        set("room_name", "Ǭ����");
        set("room_id", "qiankun");
        set("room_owner_id", "mong");
        set("room_position", "��ʯ���");
}
