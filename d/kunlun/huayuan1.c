#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "��԰");
        set("long", @long
����һ���̵�ʮ��ƽ����ʯ��·��·�汻��ɨ�ĸɸɾ���
�����ȥ�Ǹ���Բ�����������㣬�����Ǿ����ң����洫��
Щ�������������������鷿�ˡ�
long);
        set("exits",([
		"north" : __DIR__"shilu1",
		"south" : __DIR__"lang2",
	]));

	set("outdoors", "kunlun");
	setup();
	replace_program(ROOM);
}
