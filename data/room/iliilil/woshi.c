
#include <room.h>

inherit PRIVATE_ROOM;

void create()
{
	set("short", "����");
	set ("long", @LONG
�������˵����ң���ʰ�þ����������ϴ�����һ�Ŵ󴲣�������
һ�����ӡ��ƿ��������Կ�������Ļ�԰�������ᵽ�����㣬�ǳ�
��⡣Զ����һ��Ƭ���֡�
LONG );

        set("exits", ([
                "down" : __DIR__"jusuo",
        ]));

        set("sleep_room", 1);
        set("loving_room", 1);
        set("no_fight", 1);
        setup();

        set("room_owner", "ħ������");
        set("room_name", "Ѫ��ħ��");
        set("room_id", "xhmg");
        set("room_owner_id", "iliilil");
        set("room_position", "ɽ·");
}
