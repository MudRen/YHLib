// woshi.c ����������

#include <room.h>

//** inherit PRIVATE_ROOM;
inherit ROOM;                                   /* EXAMPLE */

void create()
{
	set("short", "����");
	set("long", @LONG
�������˵����ң���ʰ�þ����������ϴ�����һ�Ŵ󴲣�������һ��
���ӡ��ƿ��������Կ�������Ļ�԰�������ᵽ�����㣬�ǳ���⡣Զ
����һ��Ƭ���֡�
LONG );

	set("default_long", "�������˵����ң���ʰ�þ����������ϴ�����" /* EXAMPLE */
                            "һ�Ŵ󴲣�������һ�����ӡ��ƿ��������Կ�" /* EXAMPLE */
                            "������Ļ�԰�������ᵽ�����㣬�ǳ����" /* EXAMPLE */
                            "��Զ����һ��Ƭ���֡�");                   /* EXAMPLE */
                                                                       /* EXAMPLE */

        set("exits", ([
                "down" : __DIR__"jusuo",
        ]));

//**    set("sleep_room", 1);
//**    set("loving_room", 1);
        set("no_fight", 1);
        setup();
//**
//**    set("room_owner", "ROOM_OWNER");
//**    set("room_name", "ROOM_NAME");
//**    set("room_id", "ROOM_ID");
//**    set("room_owner_id", "ROOM_OWNER_ID");
//**    set("room_position", "ROOM_POSITION");
}
