#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short",HIW "�������á�" NOR);
	set("long", @LONG
�����ռ������ġ������á����й��Ŵ����������ľ�����������
���ԡ���ֻ��������������������������������߹����ĵط�����
���ʯ��(bei)�Ͽ����Ա����롾�����á����������֣� ��ǰ�߿���
ͨ��������˵ĳ����ҡ�
LONG
	);

	set("exits", ([ 
                "out" : "/clone/megazine/room/secondroom",
        ]));

        set("item_desc",([ "bei" : HIR "Ŀǰ�������á��ڻ�û�����ˡ�\n" NOR, ]));
	set("no_fight", 1);
        create_door("out", "����", "enter", DOOR_CLOSED);
     	setup();
        replace_program(ROOM);
}
