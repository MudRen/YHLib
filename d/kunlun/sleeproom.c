#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
        set("long", @long
�����Ǻ�̫����谮�ĵ���С���õ��Է�����һ������
�Ǳ���һ��ҩ�������滹���ŵ�һ��ʮ�ֹŹֵ���Ϣ������Ƭ
�̣�����������Ϣ��Ũ�������������ء���������һ���ˣ���
����������������������ǳ��ŷ��䡣���Ӷ��ǽ������š�
long);
	set("exits", ([
		"east" : __DIR__"tieqinju",
	]));

        set("no_clean_up", 0);
	create_door("east", "С��", "west", DOOR_CLOSED);
        setup();
        replace_program(ROOM);
}
