
#include <room.h>

inherit PRIVATE_ROOM;

void create()
{
	set("short", "����");
	set ("long", @LONG
�����Ѫ��ħ������ħ��������Ϣ������ĵط���¥�Ͼ������˵����ң�
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
    
        set("room_owner", "ħ������");
        set("room_name", "Ѫ��ħ��");
        set("room_id", "xhmg");
        set("room_owner_id", "iliilil");
        set("room_position", "ɽ·");
}
